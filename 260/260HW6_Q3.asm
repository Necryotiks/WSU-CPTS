# Newtons Method
# g(x) = x^1/3
# g'(x) = 1/3x^-2/3
# cube root formula is x2=(1/3)(2x1 +(a/x1^2) where a is the number we are cube rooting and x1 is intial guess
.text
.global main
main:
l.s $f0,a #$f0 holds a
l.s $f1,initialx #$f1 holds x1
l.s $f15,check
li $s0,0 #run count
jal newton
j EXIT

newton:
addi $s0,$s0,1
l.s $f31, Onethird #$f31 is temp register to hold 1/3
l.s $f30,Two
mul.s $f29,$f30,$f1 #$f29 holds 2 * x1
mul.s $f28,$f1,$f1 #$f28 holds x1^2
div.s $f27,$f0,$f28 #holds a/x1^2
add.s $f26 $f29,$f27 #holds 2x1+(a/x1^2)
mul.s $f2, $f31,$f26 #holds (1/3)2x1+(a/x1^2)
mov.s $f1,$f2 #x2 become x1
#check if require precision is met
beq $s0,4,JMP
j newton
JMP:
mov.s $f12,$f2
jr $ra
EXIT:
li $v0,2
syscall
li $v0,10
syscall


.data
a: .float 3.0
initialx: .float 2.5
check: .float 1.442
Onethird: .float 0.3333
Two: .float 2.0

