datos = raw_input('Dame datos: ')
doc = open(r'/media/usb/'+str(datos.split(' ')[0]), 'w')
for i in range(0, int(datos.split(' ')[1])+1):
    doc.write(str(i)+',Hola USB,data'+str(i)+'\n')
