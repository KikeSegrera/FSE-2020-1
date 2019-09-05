	.text
	.global main

main:
	mov	r7,#4		@llamada al sistema WRITE = 4 
	mov	r0,#1		@numero de archivo al que se va a escribir to STDOUT = 1
	ldr	r1,=message	@puntero al mensaje 
	mov 	r2,#18		@numero de bytes a escribir
	svc	#0		@escribe el mensaje
	mov	r7,#1		@llamada al sistema SYSCALL_EXIT = 1
	mov	r0,#0		@regresa 0
	svc	#0		@se ejecuta la salida (bx lr)
       .data

message:
       .ascii "FSE2020-1 is cool\n"
