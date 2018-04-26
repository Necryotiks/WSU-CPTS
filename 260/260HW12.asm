.text
main:
.eqv    RECR 0xffff0000      # Receiver Control Register     (Ready Bit)
.eqv    REDR 0xffff0004      # Receiver Data Register    (Key Pressed - ASCII)
.eqv    TRCR 0xffff0008      # Transmitter Control Register  (Ready Bit)
.eqv    TRDR 0xffff000c      # Transmitter Data Register (Key Displayed- ASCII)

 la $t0, 0xFFFF0008   #$t0 = 0xFFFF0008
 lw $t1, 0($t0)
 ori $t1,$t1,1        #Set Transmitter bit
 sw $t1,0($t0)

 la $t0, 0xFFFF0000
 lb $t1, 0($t0)
 ori $t1,$t1,1       #Set Interupts.
 sb $t1, 1($t0)
 li $t8,0 #offset
INTLOOP:
	addi $s3,$s3,1
	j INTLOOP

MYINTHANDLE:
sw $ra 0($sp)
jal RECEIVE
jal STORE
jal EVALUATE
lw $ra 0($sp)
jr $ra
RECEIVE:
la $t0, REDR
lbu $v0,0($t0)
jr $ra
STORE:
la $t9,expBuffer
add $t7,$t9,$t8
sb $v0,0($t7)
jr $ra
EVALUATE:
la $t9,expBuffer
add $t7,$t9,$t8
lb $t0,0($t7)
beq $t0,61,CONVERT
addi $t8,$t8,1
jr $ra
CONVERT:
EXE:
addi $t8,$t8,1
la $t0,expBuffer
lbu $t1, 0($t0)
lbu $t2 2($t0)
subi $v0, $t1, 48 #convert ascii to string
subi $v1, $t2, 48
add $v0,$v0,$v1
move $s0,$v0 #s0 contains final answer

#//POLLING BROKE, FELL BACK ON SYSCALLS
#blt $s0,10,DIGIT
#li $s3,10
#div $s0,$s3
#mfhi $t0
#DIGIT:
#addu $t5,$s0,48
#TCHECK:
#lw $t4,TRCR
#andi $t4,$t4,1
#beqz $t4,TCHECK
#sb $t5,TRDR
#jr $ra

la $a0, expBuffer
li $v0,4
syscall
move $a0,$s0
li $v0,1
syscall
jr $ra

#transmit here
#beq $t8,3,COMPUTE


.data
expBuffer: .space 60
expLen: .word 0
.ktext 0x80000180
#save registers sometime
#maybe load regBuffer into $s1
#la $s1,regBuffer
#sw $at,0($s1)
#sw $t0,4($s1)
#w $t1,8($s1)
#sw $t2,12($s1)
#sw $t7,16($s1)   this breaks things
#sw $t8,20($s1)
#sw $t9,24($s1)
#sw $v0,26($s1)
#sw $v1,30($s1)
#sw $a0,34($s1)
#sw $s0,38($s1)

CHECKCAUSE:
#may need intermediate register
andi $t0,$13,0x04
bnez $t0,RECOVER
andi $t0,$13,0x08 #
bnez $t0,RECOVER
andi $t0,$13,0x010
bnez $t0,RECOVER
andi $t0,$13,0x20
bnez $t0,RECOVER
andi $t0,$13,0x40

CHECKINT:
andi $t0,$13,0x100
bnez $t0,RECOVER

INTHAND:
la $k0,MYINTHANDLE
jalr $k0

CLEARCAUSE:
mtc0 $zero,$13

RESETSTATUS:
li $t1,1
mtc0 $t1, $12
la $t0, 0xFFFF0000
lb $t1, 0($t0)
ori $t1,$t1,1       #Set Interupts.
sb $t1, 1($t0)


RECOVER:
#lw $at,0($s1)
#lw $t0,4($s1)
#lw $t1,8($s1)
#lw $t2,12($s1)
#lw $t7,16($s1)
#lw $t8,20($s1)
#w $t9,24($s1)
#lw $v0,26($s1)
#lw $v1,30($s1)
#lw $a0,34($s1)
#lw $s0,38($s1)
eret
.kdata
regBuffer: .space 128

