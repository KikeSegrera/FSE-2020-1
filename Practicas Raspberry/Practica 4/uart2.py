import serial

ser=serial.Serial("/dev/ttyS0", 115200)
cadena=""
ser.write("\n\r")
while(True):
	recibido=ser.read()
	ser.write(recibido)
	if str(recibido)=="\r":
		break;
	if ord(str(recibido))==127:
		cadena=cadena[:len(cadena)-1]
	else:
		cadena+=str(recibido)
try:
	lista=cadena.split(",")
	salida=""
	for i in range(0, len(lista)):
		if i==0:
			salida+="Numero: "
			if int(lista[i]) in range(0,4096):
				salida+=lista[i]+"\n\r"
			else:
				salida+="XXXX\n\r" 
		if i==1:
			salida+="Iniciales: "
			if lista[i]=="MED":
				salida+=lista[i]+"\n\r"
			else:
				salida+="XXXX\n\r"
		if i==2:
			salida+="Bandera: "
			if int(lista[i])==0 or int(lista[i])==1:
				salida+=lista[i]+"\n\r"
			else:
				salida+="X\n\r"
		if i==3:
			salida+="Voltaje: "
			if float(lista[i])>=0.0 and float(lista[i])<=3.3:
				salida+=lista[i]
			else:
				salida+="XXX"
	print(salida)
except:
	print("Numero: XXXX\nIniciales: XXXX\nBandera: X\nVoltaje: XXX")



