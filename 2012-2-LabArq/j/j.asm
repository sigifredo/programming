
.data
    numeros1: .word 1,2,2,4,2,4,7,1 # N 8
    numeros2: .word 1,2,3,4,5,6,7,9,9 # M 9

.text
    la $a0, numeros1 # leemos la dirección del arreglo.
    li $a1, 8 # N

    jal repetidos
    move $a0, $v0

    # imprimir
    li $v0, 1
    syscall

    la $a0, numeros2 # leemos la dirección del arreglo.
    li $a1, 9 # N

    jal repetidos
    move $a0, $v0

    # imprimir
    li $v0, 1
    syscall

    li $v0, 10 # exit program
    syscall

repetidos:
    addi $t0, $zero, 0 # i
    addi $t2, $zero, 0 # contador

    loop1:
        beq $a1, $t0, endl1

        addi $t1, $t0, 1
        loop2:
        beq $a1, $t1, endl2

        # $t3 = v[i]
        sll $t3, $t0, 2
        add $t3, $a0, $t3
        lw $t3, 0($t3)

        # $t4 = v[j]
        sll $t4, $t1, 2
        add $t4, $a0, $t4
        lw $t4, 0($t4)

        # (v[i] == v[j] && i != j && i !=-1)
        bne $t3, $t4, endif1
        beq $t0, $t1, endif1

            addi $t5, $t1, 1 # k = j+1
            loop3:
                beq $t5, $a1, endl3

                # $t4 = v[k]
                sll $t6, $t5, 2
                add $t6, $a0, $t6
                lw $t7, 0($t6)

                bne $t3, $t7 endif2
                    addi $t3, $zero, -1
                    sw $t3, 0($t6)
                endif2:

                addi $t5, $t5, 1 # k++
                j loop3
            endl3:

            addi $t2, $t2, 1

        endif1:

        addi $t1, $t1, 1
        j loop2
	endl2:

	addi $t0, $t0, 1
	j loop1
    endl1:

    add $v0, $t2, $zero
    jr $ra
