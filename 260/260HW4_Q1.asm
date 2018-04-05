.text
.global main
main:
li $t0,0
li $t1,0
la $a0,query
li $v0, 4
syscall
#$t0 -> input $t1 -> index
la $a0,arrA
li $a1, 64
li $v0,8
syscall
PROCESSLOOP:
lb $t0,arrA($t1)
beqz $t0,DEL
addi $t1,$t1,1
j PROCESSLOOP
DEL:
lb $t0,arrA($t1)
beq $t0,65,REM
beq $t0,97,REM
addi $t1,$t1,-1
j DEL
REM:
li $t0,32
sb $t0,arrA($t1)
la $a0,arrA
li $v0,4
syscall
.data
arrA: .space 64
query: .asciiz "Enter string(ESC to quit):\n "
