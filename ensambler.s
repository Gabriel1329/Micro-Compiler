        .text
        .globl main
main:
	la $t5, 1
	add $a3, 2, $t5
	add $t1, $a3, $zero

	jr $ra