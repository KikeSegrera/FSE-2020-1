# FSE-ESP32: Práctica 3 (Examen Parcial 1)

## Integrantes
* Alvarado Díaz Marco Antonio
* Martínez Segrera Daniel Enrique
* Salinas Navarro Diego Alberto

## Objetivos
* Medir la temperatura utilizando el sensor LM335 y el convertidor analógico-digital del ESP32.
* Comunicar la Raspberry PI con el ESP32 a través de la comunicación serial.
* Comunicar la Raspberry PI con la computadora a través de la comunicación USB serial.

## Desarrollo
1. Procesamiento de datos en el ESP32 y comunicación entre el ESP32 y la Raspberry PI: Se creó un programa en C que leyera el voltaje lanzado por el sensor LM335, lo convirtiera a un valor númerico a través del convertidor analógico-digital del ESP32 y finalmente enviara el dato a través de un puerto serial UART previamente configurado a la Raspberry PI.
2. Procesamiento de datos en la Raspberry PI y comunicación con la computadora: Se implementó un programa en Python que procesara los datos previamente recibidos del ESP32,les diera un formato específico y los enviara a través del USB serial a la computadora.
3. Datos finales en la computadora: Los datos son mostrados en la consola serial de la computadora.

[Video]()
