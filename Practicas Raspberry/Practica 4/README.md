# FSE-Práctica 4: Raspberry Pi

## Integrantes
* Alvarado Díaz Marco Antonio
* Martínez Segrera Daniel Enrique
* Salinas Navarro Diego Alberto

## Objetivo
* Conocer la configuración, programación y uso del módulo UART en la tarjeta de desarrollo Raspberry Pi, para implementar comunicaciones de tipo serial bajo el estándar RS-232.

## Desarrollo
1. Como primer paso se habilitó la comunicación UART con la Raspberry Pi mediante el archivo de configuraciones. También fue necesario deshabilitar la consola desde UART para poder observar los datos que se mandaran a través de dicho puerto.
1. Para verificar esta comunicación se utilizó "minicom" que permite emular un monitor para la comunicación UART entre la terminal en nuestra computadora y la Raspberry.
1. Una vez que la comunicación funcionó correctamente, se procedió a realizar las siguientes actividades:
   1. Un programa en Python que escriba una cadena quince veces en la terminal de la PC, se encuentra en el código `uart1.py`.
   1. Un programa en Python que lea una cadena proveniente desde la PC separada por comas y la imprima con un formato específico en la terminal de la Raspberry Pi, se encuentra en el código `uart2.py`.

[Video]()
