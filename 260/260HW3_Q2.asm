.text 	#s0 -> address of arrA, $t0 -> i i.e index of the array,$t1 -> counter,$t2-$t4-> temp registers,$t9->swap variable 
.global main
main:
li $t0,0
li $t2,0
li $v0,4
la $a0,query
syscall

LOOP1:
beq $t1,6,EXIT1 #check if max number of integers reached
li $v0, 5
syscall		#syscall to read integers
sw $v0,arrA($t0)#stores values in arrA
addi $t0,$t0,4	#increments offset
addi $t1,$t1,1	#increments counter
j LOOP1
EXIT1:
li $t0,0
li $t1,0	#reset our counters
lw $t2, arrA($t0)
addi $t1,$t1,1	#increments counter
addi $t0,$t0,4
LOOP2: 		#Orders registers
bge $t1,6,EXIT2 #check if max number of integers reached
bgt $t3,$t4,SEQ2 #If t3 < t4 then swap
move $t9,$t3
move $t3,$t4
move $t4,$t9
bge $t1,6,EXIT2
bgt $t3,$t4,SEQ2 #If t3 < t4 then swap
lw $t3 arrA($t0)
addi $t1,$t1,1
addi $t0,$t0,4
bgt $t2,$t3,SEQ1 # If t2 < t3 then swap
move $t9,$t2
move $t2,$t3
move $t3,$t9
SEQ1:
bgt $t3,$t4,SEQ2 #If t3 < t4 then swap
move $t9,$t3
move $t3,$t4
move $t4,$t9
SEQ2:
bge $t1,6,EXIT2
lw $t4 arrA($t0)
addi $t1,$t1,1
addi $t0,$t0,4	
j LOOP2
EXIT2:
la $a0,final #prints final string
li $v0,4
syscall
add $a0,$t3,$zero #loads expected value to print
li $v0,1
syscall
li $v0,10	#terminate program
syscall
.data
arrA: .space 24
query: .asciiz "Enter numbers:\n"
final: .asciiz "Second largest number: "
