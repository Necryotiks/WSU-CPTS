.text
.global main
main:
	#s0 -> x,$s1 -> y,$t0 -> x-5,$t1 -> x+2y-z $s2 -> z
li $s0,12
addi $t0,$s0,-5
move $s1,$t0
jal simpleEx
move $t1,$a0 #save the return from the first function call
move $s1,$s0
li $s0,14
jal simpleEx
add $a0,$a0,$t1
j EXIT

simpleEx:
addi $sp,$sp,-12
sw $s0,0($sp)
sw $s1 4($sp)
sw $ra 8($sp)
sll $t2,$s1,1 #$t2 -> 2y 
add $t3,$s0,$t2 #$t3 -> x+2y
subi $a0,$t3,7 #x+2y-z 
lw $ra, 8($sp)
lw $s1, 4($sp)
lw $s0, 0($sp)
addi $sp,$sp,12
jr $ra
 EXIT:
li $v0, 1
syscall
li $v0,10
syscall


.data
