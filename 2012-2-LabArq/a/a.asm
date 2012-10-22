
.data
    numeros: .word 8, 2, 3, 4, 5, 6, 7, 8, 9

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
    addi $t0, $zero, 0 # i
    addi $t1, $zero, 0 # contador

    loop:
    	sll $t3, $t0, 2 # $t3 = v[i]

        lw $t5, 0($a0)

        add $t6, $a0, $t3
        lw $t6, 0($t6)
    	slt $t4, $t5, $t6 # $t4 = (v[0] < v[i])
    	beq $t4, $zero, endif
    	    addi $t1, $t1, 1 # contador++;
    	endif:

	addi $t0, $t0, 1 # i++
	bne $a1, $t0, loop  # si i != n, salte a loop
    endl:

    add $v0, $t1, $zero
    jr $ra
    
    
    
