        .text
        .globl main
main:
	li $v0, 5
	add $t0, $v0, $zero
	syscall

	li $v0, 5
	add $t1, $v0, $zero
	syscall

	li $v0, 1
	add $t0, $v0, $zero
	syscall

	li $v0, 1
	add $t1, $v0, $zero
	syscall

