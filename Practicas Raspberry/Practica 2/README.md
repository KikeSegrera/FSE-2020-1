# FSE-Práctica 2: Raspberry Pi

## Integrantes
* Alvarado Díaz Marco Antonio
* Martínez Segrera Daniel Enrique
* Salinas Navarro Diego Alberto

## Comentarios y Respuestas a las preguntas:

a. ¿Cuál es la diferencia entre las instrucciones swi 0x0, svc #0 y bx lr?
   - swi 0x0 : Por sus siglas hace referencia a una interrupción de software (SoftWare Interrupt), esta instrucción ocasiona que el procesador cambie a estado ARM, a modo Supervisor, el CPSR se salva en el Modo Supervisor y la ejecución se ramifica al vector SWI. El parámetro "0x0" es ignorado por el procesador, pero al estar presente en 8 bits del opcode, puede ser recuperado por el manejador de excepciones para determinar qué servicio se requiere.
   - svc #0 : Esta instrucción es la "evolución" de la instrucción SWI, y lo que hace es generar una llamada al supervisor (SuperVisor Call). Estas llamadas son normalmente utilizadas para solicitar operaciones privilegiadas o acceder a recursos del SO. Para poder utilizarla es necesario pasar los parámetros a los registros de propósito general.
   - bx lr : Sus siglas quieren decir que se realiza una ramificación con intercambio (Branch eXchange) y el parámetro que se le pasa es el registro lr (Link Register). Lo que hace la instrucción bx es que, dependiendo del bit menos significativo del registro que se pasa como parámetro, el procesador cambia a modo ARM (si vale 0) o a modo Thumb (si vale 1). En este caso, como se pasa el registro de retorno (lr), la instrucción permite que se regrese el control al programa que se inició.

b. ¿A qué se refiere la instrucción .balign 4 en el lenguaje ensamblador para ARM?
   - La instrucción .balign es una directiva que permite modificar el contador de ubicación (en la subsección actual) a un límite de almacenamiento particular. Esto implica que la dirección del siguiente dato o instrucción será un múltiplo del parámetro establecido, en este caso sería un múltiplo de 4. Si la dirección ya se encuentra alineada, la instrucción no hace nada; en caso contrario, se emiten "bits de relleno" (padding bits), que no son utilizados por el programa más que para lograr el alineamiento.

c. ¿Cuántas instrucciones en lenguaje ensamblador hay para la arquitectura ARM11 y cuántos modos de direccionamiento hay (nómbrelos)?
   - Soporta tanto las instrucciones de ARM como las de Thumb, para un total de 223 instrucciones (http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0489i/Cjafgdih.html)
   - Existen 5 modos de direccionamiento:
        	1. Operandos de procesamiento de datos.
		2. Carga y Almacenamiento de Palabra o Byte sin signo.
		3. Carga y Almacenamiento misceláneo.
		4. Carga y Almacenamiento múltiple.
		5. Carga y Almacenamiento de coprocesador.
