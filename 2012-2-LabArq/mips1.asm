.data					# directiva para pespacio de variables

vector:	.word 0:10			# reserva 10 posiciones tipo word
tam: 	.word 10			# vble tam = 10
result:	.word 0

.text					# se ubica en almacenamiento de programa
la $t0, vector
la $t1, tam				# dirección de tam en t1
lw $t2, 0($t1)				# t2 = 10
addi $t3, $zero, 0
addi $t6, $zero, 0			# inicializamos temp=0

loopllenar:	sll $t7, $t3, 2		#t7 = 2^2 * t3
		add $t4, $t0, $t7	# $t4 = &vector[i]
		sw $t3, 0($t4)		# vector[i] = i
		addi $t3, $t3, 1
		bne $t3, $t2, loopllenar

addi $t3, $zero, 0			# inicializamos i=0

loopsuma:	sll $t7, $t3, 2
		add $t4, $t0, $t3
		lw $t5, 0($t4)		# t5=vector[i]
		add $t6, $t6, $t5	# temp = temp+vector[i]
		addi $t3, $t3, 1	# i++
		bne $t3, $t2, loopsuma	# i != tam?

la $t1, result				# t1 = &result
sw $t6, 0($t1)

# fin