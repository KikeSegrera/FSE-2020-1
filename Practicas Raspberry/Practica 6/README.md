# FSE-Práctica 6: Raspberry Pi

## Integrantes:
* Alvarado Díaz Marco Antonio
* Martínez Segrera Daniel Enrique
* Salinas Navarro Diego Alberto

## Objetivo
El alumno aprenderá a utilizar el protocolo I2C para configurar un reloj DS1307 y para obtener información de cada registro que lo compone para obtener la hora y fecha con un formato específico y se almacenará en una memoría usb.
## Desarrollo
Se habilitó la comunicación I2C en la raspberry y se creó un programa en python que utiliza las funciones necesarias con la finalidad leer los registros y escribir dentro de ellos para establecer la hora del reloj DS1307 y al momento de realizar la consulta de la hora almacenar en una USB el archivo que contenga la fecha y la hora con determinado formato, en nuestro caso fue:
* Año, mes, día, hora, minutos, segundos.
