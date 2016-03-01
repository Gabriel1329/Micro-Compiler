        .text
        .globl main
main:   li $v0, 1       # syscall 1 (print_integer)
        la $a0, 5       # argument: integer
        syscall         # print the string
        lw $t1, foobar
        
        jr $ra          # retrun to caller



write:
	li $v0, 1       # syscall 1 (print a integer)
	la $a0, 5       # argument: integer

Read:
	li $v0, 5	# syscall 5 (read a integer)
			# integer leido queda en $v0
	add $a0, $v0, $zero

+:
	add $1,$2,$3 	$1 = $2 + $3 (con signo)

-:
	sub $1,$2,$3 	$1 = $2 - $3 (con signo)

registros 
$at $v0 $v1 $a0 $a1 $a2 $a3 $t0 $t1 $t2 $t3 $t4 $t5 $t6 $t7 $t8 $t9 $s0 $s1 $s2 $s3 $s4 $s5 $s6 $s7 $k0 $k1 $gp $sp $fp $ra

a := 3+(100-2); 

la $t0, 100
la $t1, 2
add $t3, $t0, $t1
la $t0, 3
add $t3, $t0, $t3

la $t0, 100
add $t1, $t0, $zero
la $t0, 2
sub $t1, $t1, $t0
la $t0, 3
add $t1, $t1, $t0


