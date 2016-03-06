        .text
        .globl main
main:
	li $a2, 2
	addi $a3, $a2, 4
	add $t4, $a3, $zero

	jr $ra