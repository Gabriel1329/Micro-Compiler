        .text
        .globl main
main:   
	la $t2,2
	addi $t2,$t2,3

	la $v0, 1       # syscall 1 (print_integer)
        add $a0, $t2, $zero        # argument: integer
        syscall         # print the string
        
        jr $ra          # retrun to caller
