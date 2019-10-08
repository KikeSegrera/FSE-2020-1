import serial

ser=serial.Serial("/dev/ttyS0", 115200)
for i in range(0,16):
	ser.write(str(i)+": FSE 2020-1 Comunicacion UART RPi - FSE\n\r")

