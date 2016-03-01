        .text
        .globl main
main:
	li $v0, 5
	syscall
	add $t0, $v0, $zero

	li $v0, 5
	syscall
	add $t1, $v0, $zero

	la $t4, 12
	add $a3, $t4, $t1
	add $a3, $t0, $a3

	li $v0, 1
	add $a0, $a3, $zero
	syscall

	la $t9, 23
	add $a3, $t1, $t9

	li $v0, 1
	add $a0, $a3, $zero
	syscall

	li $v0, 1
	add $a0, $t0, $zero
	syscall

	li $v0, 1
	add $a0, $t1, $zero
	syscall

	la $t4, 12
	add $a3, $t4, $t1
	add $a3, $t0, $a3

	li $v0, 1
	add $a0, $a3, $zero
	syscall

	la $s0, 4
	add $a3, $s0, $t0
	sub $a3, $t1, $a3
	sub $a3, $t0, $a3
	la $t4, 3
	add $a3, $t4, $a3
	add $t2, $a3, $zero

	add $t0, $t1, $zero

	li $v0, 5
	syscall
	add , $v0, $zero

	li $v0, 5
	syscall
	add $t5, $v0, $zero

