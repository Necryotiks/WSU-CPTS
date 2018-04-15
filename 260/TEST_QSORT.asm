.text
.global main 
main:
la $a0,arrA
li $a1,0
li $a2,6
QuickSort:
    bgt     $a1, $a2, QuickSortEnd    
    nop

    subu    $sp, $sp, 16
    sw      $ra, 6($sp)
    sw      $a0, 12($sp)
    sw      $a1, 8($sp)
    sw      $a2, 4($sp)   #save $a0, $a1, $a2, $ra
    jal Partition       #partition(v, a, b)
    nop 

    subu    $sp, $sp, 4
    sw      $v0, 4($sp)   
    lw      $a0, 16($sp)      #$a0 = v
    lw      $a1, 12($sp)      #$a1 = a
    addi    $a2, $v0, -1      #$a2 = k - 1 
    jal QuickSort
    nop

    lw      $a0, 16($sp)  #$a0 = v
    lw      $t0, 4($sp)
    addi    $a1, $t0, 1   #$a1 = k + 1
    lw      $a2, 8($sp)   #$a2 = b
    jal QuickSort
    nop

    addu $sp, $sp, 20
    lw $ra, 0($sp)    
    nop

QuickSortEnd: jr $ra
Partition:
    add $t1, $a1, $a1
    add $t1, $t1, $t1
    add $t1, $t1, $a0      #$t2 = pivot
    lw  $t2, 0($t1)       #v[a]
    nop
    addi $t3, $a1, 1      #$t3 = lower = a + 1
    addi $t4, $a2, 0      #$t4 = upper = b

Do:
blt $t4, $t3, PartitionEnd

    W1:
    add     $t8, $t3, $t3
    add     $t8, $t8, $t8
    add     $t8, $t8, $a0      
    lw      $t5, 0($t8)       #$t5 = v[lower]
    nop
    ble     $t5, $t2, W12
    nop
    b       W2
    W12:
    ble     $t3, $t4, W1_Op
    nop
    b       W2
    W1_Op:
    addi    $t3, $t3, 1
    b       W1

    W2:
    add     $t8, $t4, $t4
    add     $t8, $t8, $t8
    add     $t8, $t8, $a0      
    lw      $t5, 0($t8)       #$t5 = v[upper]
    nop
    bgt     $t5, $t2, W22
    nop
    b       f
    W22:
    ble     $t3, $t4, W2_Op
    nop
    b       f
    W2_Op:
    addi    $t4, $t4, -1
    b       W2

f:
    bgt     $t3, $t4, Do
    nop
    add     $t8, $t3, $t3
    add     $t8, $t8, $t8
    add     $t8, $t8, $a0      
    lw      $t6, 0($t8)       #temp = v[lower]
    nop

    add     $t9, $t4, $t4
    add     $t9, $t9, $t9
    add     $t9, $t9, $a0      
    lw      $t7, 0($t9)       #v[upper]
    nop

    sw      $t7, 0($t8)       #v[lower] = v[upper]
    sw      $t6, 0($t9)       #v[upper] = temp

    addi    $t3, $t3, 1
    addi    $t4, $t4, -1

j Do

PartitionEnd:
    add     $t8, $t4, $t4
    add     $t8, $t8, $t8
    add     $t8, $t8, $a0      
    lw      $t2, 0($t8)       #temp = v[upper]
    nop

    add     $t9, $a1, $a1
    add     $t9, $t9, $t9
    add     $t9, $t9, $a0      
    lw      $t3, 0($t9)       #v[a]
    nop

    sw      $t3, 0($t8)       # v[upper] = v[a]
    sw      $t2, 0($t9)       # v[a] = temp

    addi    $v0, $t4, 0       #return upper(k)
    jr      $ra
    nop
    
    .data
    arrA: .word 10,2,17,9,6,4,8
    
