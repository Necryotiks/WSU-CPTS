.text
.global main 
main:
la $a0,query
li $v0,4
syscall
li $v0,5
syscall
beqz $v0,EXIT
move $a0,$v0		#$a0 -> n
jal rec
move $a0,$v0
j EXIT


rec:
addi $sp,$sp,-12
sw $ra, 8($sp)
sw $s0, 4($sp)
sw $s1,0($sp)
move $s0,$a0
li $v0, 1 # return value for terminal condition
ble $s0, 2, subEXIT
addi $a0,$s0,-1 #holds n-1
jal rec
move $s1,$v0 #store result of f(n-1) to s1
sll $t0,$s1,1 #hold 2 * f(n-1)
addi $a0,$s0,-2 #holds n-2
jal rec
mul $t1,$v0,3  # $t1 hold 3 * f(n-2)
add $v0,$t0,$t1
subEXIT:
lw $ra, 8($sp)
lw $s0,4($sp)
lw $s1 0($sp)
add $sp,$sp,12
jr $ra

fib:
ble $s0,2,rec
li $v0,1

jr $ra
EXIT:
li $v0,1
syscall
li $v0,10
syscall
.data
query: .asciiz  "Enter a number: "
