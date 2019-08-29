	.global main
	.data
igual_men:
	.ascii "Ambos numeros son iguales\n"

mayor_r2_men:
	.ascii "El mayor es r2 y el menor r1\n"

mayor_r1_men:
	.ascii "El mayor es r1 y el menor r2\n"

main:
	mov	r1, #6
	mov	r2, #6
	cmp	r1, r2
	beq	igual
	blt	mayor_r2
	b	mayor_r1
igual:
	mov	r7,#4
	mov	r0,#1
	ldr	r1,=igual_men
	mov	r2,#26
	svc	#0
	b	end
mayor_r2:
	mov	r7,#4
	mov	r0,#1
	ldr	r1,=mayor_r2_men
	mov	r2,#29
	svc	#0
	b	end
mayor_r1:
	mov	r7,#4
	mov	r0,#1
	ldr	r1,=mayor_r1_men
	mov	r2,#29
	svc	#0
	b	end

end:
	bx lr
