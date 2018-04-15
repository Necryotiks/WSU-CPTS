;$t0, 0xffff0000      recv ctrl
;$t1, 0xffff0004       recv buf
;$t2, 0xffff0008       trans ctrl
;$t3, 0xffff000c       trans buf

main:
    lui $t0, 0xFFFF0008   #$t0 = 0xFFFF0000
    lw $t1, 0($t0)
    ori $t1,$t1,0x0001
    sw $t1, 0($t0)
    lui $t0, 0xFFFF0000   #$t0 = 0xFFFF0000
    lui $t1, 0xFFFF0004   #$t0 = 0xFFFF0000
    lui $t2, 0xFFFF0008   #$t0 = 0xFFFF0000
    lui $t3, 0xFFFF000c   #$t0 = 0xFFFF0000
    la $s1, buffer
    li $t9,0
poll:                 # polling procedure
    lw $t4,0($t0) 
    andi $t4, $t4, 0x0001
    beq $t4, $zero, poll 
    lbu $s0, 0($t1)    # load word into register $a0
    sb $s0, $t9(s1)

.data
buffer: .space 1
