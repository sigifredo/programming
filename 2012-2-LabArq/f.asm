
.data
    numeros: .word 1, 2, 3, 4, 5, 6, 7, 8, 9

.text
    la $s0, numeros # leemos la dirección del arreglo.

    li $t0, 9 # N
    li $t1, 0 # i
    li $a0, 0 # impares

    loop:
        lw $t3, 0($s0) # obtenemos el valor del primer elemento del arreglo.
        andi $t3, $t3, 1 # $t3 = ($t3 & 1)
        beq $t3, 1, contar # si es impar, contar el número
        j nocontar # sino, no lo cuento
        contar:
        addi $a0, $a0, 1
        nocontar:
        addi $s0, $s0, 4 # incremento el puntero del arreglo
        addi $t1, $t1, 1 # incremento el índice
        beq $t0, $t1, imprimir # si llegamos al final del arreglo, imprimir
        j loop # saltar al principio del ciclo

    imprimir:
        li $v0, 1
        syscall
