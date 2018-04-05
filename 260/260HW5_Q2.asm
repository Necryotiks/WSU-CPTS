.text
.global main
main:
la $a0, query
li $v0, 4
syscall
li $v0,5
syscall
move $a0,$v0 #$a0 -> k
ble $a0, 3 CASE #Checks if k is valid
li $t0,2 #unsquared values
sll $t1,$t0,1#$t1 holds accumlator(i.e squared values)
LOOP:
beq $t1,$a0,EXIT
add $t0,$t0,2 #holds 4,6,8,...
mul $t2,$t0,$t0 #checks if new value will exceed k
add $t3,$t2,$t1
bgt $t3,$a0,CASE2
add $t1,$t2,$t1
j LOOP

CASE:
li $a0,0
j EXIT
CASE2:
move $a0,$t1
j EXIT
EXIT:
move $a0,$t1
li $v0,1
syscall






.data:
query: .asciiz "Enter a number: "
