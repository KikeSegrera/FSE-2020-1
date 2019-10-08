from DS1307 import *
import time

def main():
    ds = DS1307(1,0x68)

    datos = raw_input('Nombre archivo: ')
    doc = open(r'/media/usb/'+str(datos), 'w')
    try:
        while True:
            data = str(ds.read_datetime())
            #data = data.replace('(','')
            #data = data.replace(')','')
            #data = data.replace(' ','')
            doc.write(data+'\n')
            time.sleep(1)
    except KeyboardInterrupt:
        pass

main()
