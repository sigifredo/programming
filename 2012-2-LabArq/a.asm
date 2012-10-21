
.data
    numeros: .word 60, 2, 3, 4, 5, 6, 7, 8, 69

.text
    la $a0, numeros # leemos la dirección del arreglo.
    li $a1, 9 # N

    jal mayores
    move $a0, $v0

    imprimir:
    li $v0, 1
    syscall

    li $v0, 10 # exit program
    syscall

mayores:
    li $t0, 0 # i
    li $t1, 0 # contador
    
    loop:
    	sll $t3, $t1, 2 # $t3 = v[i]

    	# if(v[i] > v[0])
    	lw $t5, 0($a0)

        add $t6, $a0, $t3
        lw $t6, 0($t6)
    	slt $t4, $t5, $t6 # $t4 = (v[0] < v[i])
    	beq $t4, $zero, endif
    	    addi $t1, $t1, 1 # contador++;
    	endif:

	addi $t0, $t0, 1 # i++;
	bne $a1, $t1, loop  # si i != n, salte a loop
    endl:

    add $v0, $t1, $zero
    jr $ra
    
    
    