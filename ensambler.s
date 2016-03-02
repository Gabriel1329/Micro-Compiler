        .text
        .globl main
main:
	la $s0, 19
	la $t8, 4
	add $a3, $t8, $s0
	la $t6, 2
	sub $a3, $t6, $a3
	la $t4, 5
	sub $a3, $t4, $a3
	la $t2, 3
	add $a3, $t2, $a3
	add $t0, $a3, $zero

	li $v0, 1
	add $a0, $t0, $zero
	syscall

	jr $ra