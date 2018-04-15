.text
.global main
main:
li $s0,0             #1a
li $s1,0
addi $t0,$s1,5       #Convention:
ble $s0, $t0, ELSE   #$s0 -> x, $s1 -> y, $t0 -> y+5
add $s0,$s0,$s1
ELSE:
sub $s1,$s1,$s0

LOOP1:               #1b
addi $t0,$s1,5
blt $s0,$t0,EXIT1
subi $s0,$s0,1
subi $s0,$s0,1
addi $s1,$s1,1
j LOOP1

EXIT1:
li $s0,1             #1c
LOOP2:
bge $s0,$s1,EXIT2
addi $s0,$s0,5
addi $s1,$s1,1
addi $s0,$s0,1
j LOOP2

EXIT2:
li $v0,10
syscall


