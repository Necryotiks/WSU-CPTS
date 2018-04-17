#$t0, 0xffff0000      recv ctrl
#$t1, 0xffff0004       recv buf
#$t2, 0xffff0008       trans ctrl
#$t3, 0xffff000c       trans buf

main:
.eqv    RECR 0xffff0000      # Receiver Control Register     (Ready Bit)
.eqv    REDR 0xffff0004      # Receiver Data Register    (Key Pressed - ASCII)
.eqv    TRCR 0xffff0008      # Transmitter Control Register  (Ready Bit)
.eqv    TRDR 0xffff000c      # Transmitter Data Register (Key Displayed- ASCII)

    la $t0, 0xFFFF0008   #$t0 = 0xFFFF0000
    lw $t1, 0($t0)
    ori $t1,$t1,0x0001
    sw $t1, 0($t0)
    la $s1, buffer
    li $t9,0 #offset
    li $t8,0 #counter
poll:                 # polling procedure
    lw $t4,RECR
    andi $t4, $t4, 1
    beq $t4, $zero, poll 
    lbu $s0, REDR    # load byte into register $a0
    sb $s0, 0($s1)
    addi $s1,$s1,1
    
displayWait:
    lw      $t1,TRCR               # get control reg
    andi    $t1,$t1,1               # isolate ready bit
    beq     $t1,$zero,displayWait   # is display ready? if no, loop

    sb      $s0,TRDR                 # send key to display
    
    
    
    li $v0,11
    syscall
    addi $t8,$t8,1
    bne $t8, 4,poll
        subi $s1,$s1,1    
        subi $s1,$s1,1    
        subi $s1,$s1,1
        subi $s1,$s1,1
   
char2num:
    lb $t7, 0($s1)
    lb $t6 2($s1)
    subi $v0, $t7, 48 #convert ascii to string
    subi $v1, $t6, 48
    add $v0,$v0,$v1
    move $s2,$v0
    la $a0, buffer
    li $v0,4
    syscall
    move $a0,$s2
    li $v0,1
    syscall
.data
buffer: .space 5
asciiZero: .byte '0'
