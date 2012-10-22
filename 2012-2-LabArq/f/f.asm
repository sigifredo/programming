
.data
    numeros: .word 1, 2, 3, 4, 5, 6, 7, 8, 9

.text
    la $a0, numeros # leemos la dirección del arreglo.
    li $a1, 9 # N

    jal impares
    move $a0, $v0

    imprimir:
    li $v0, 1
    syscall

    li $v0, 10 # exit program
    syscall

impares:
    li $t0, 0 # i
    li $t1, 0 # impares

    loop:
        beq $a1, $t0, endl

        sll $t3, $t0, 2
        add $t4, $a0, $t3
        lw $t4, 0($t4)

        andi $t4, $t4, 1 # $t4 = ($t4 & 1)
        addi $t5, $zero, 1 # $t5 = 1

        bne $t4, $t5, endif
            addi $t1, $t1, 1
        endif:

        addi $t0, $t0, 1 # i++
        j loop
    endl:
    
    add $v0, $t1, $zero

    jr $ra
