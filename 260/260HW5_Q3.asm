#Only sorts 60% of the array.
.text
.global main
main:	#s0 -> low index,$s1 -> high index,$s2 -> partition index,$s3-> holds pivot $a0 holds arrA
li $s0,0
li $s1,6
jal quickSort
j EXIT


quickSort:
bge $s0,$s1,EXIT2
addi $sp,$sp -16
sw $ra,0($sp)
sw $s0,4($sp) #holds low index
sw $s1,8($sp)#holds high index
sw $s2,12($sp) #holds partition index
jal part
move $t8,$s1
move $s1,$s2
#bge $s0,$s1,EXIT1
jal quickSort
move $s1,$t8
move $t8,$s0 # $t8 holds old low
addi $s0,$s2,1 #low holds p+1
#bge $s0,$s1,EXIT2
jal quickSort
move $s0,$t8
lw $ra, 0($sp)
lw $s0, 4($sp)
lw $s1 ,8($sp)
lw $s2,12($sp)
addi $sp,$sp 16
EXIT2:
jr $ra

part:
mul $t9,$s0,4
lw $s3,arrA($t9) #holds pivot = arrA[low]
add $t0,$s0,-1 #holds i = (low -1)
add $t1,$s1,1 #holds j = hi +1
MLOOP:
LOOP1:
addi $t0,$t0,1
sll $t3,$t0,2 #t4 holds 4*i offset
lw $t5,arrA($t3) #holds a[i]
bge $t5,$s3,LOOP2
j LOOP1
LOOP2:
addi $t1,$t1,-1
mul $t4,$t1,4 #t4 holds 4*j offset
addi $t4,$t4,-4
lw $t6,arrA($t4) #holds a[j]
ble $t6,$s3,RET
j LOOP2
RET:
blt $t0,$t1, RET2
move $s2,$t1
jr $ra
RET2:
sw $t5,arrA($t4)
sw $t6,arrA($t3)
j MLOOP

EXIT:
la $a0,arrA
li $v0,10
syscall

.data
arrA: .word 10,2,17,9,6,4,8
