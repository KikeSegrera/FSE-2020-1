import serial

ser=serial.Serial("/dev/ttyS0", 115200)
cadena=""
ser.write("\n\r")
while(True):
	recibido=ser.read()
	if str(recibido)=="\r":
		temp=float(cadena[0:len(cadena)])
		ser.write("\n"+"Volt: "+str(temp)+"mV\n")
		ser.write(str(chr(176))+"C: "+str((temp-2731.5)/10)+"\n")
		ser.write(str(chr(176))+"K: "+str(temp/10)+"\n")
		cadena=""
	else:
		cadena+=str(recibido)
