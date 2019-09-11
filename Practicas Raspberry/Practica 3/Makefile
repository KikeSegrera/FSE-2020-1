CC = gcc
CFLAGS = -O2 -Wall
LFLAGS =


all:	blink_led read_switch

blink_led:	blink_led.o
	$(CC) $(LFLAGS) -o blink_led blink_led.o

blink_led.o:	blink_led.c
	$(CC) $(CFLAGS) -c blink_led.c

read_switch:	read_switch.o
	$(CC) $(LFLAGS) -o read_switch read_switch.o

read_switch.o:	read_switch.c
	$(CC) $(CFLAGS) -c read_switch.c

submit:	blink_led.c read_switch.c Makefile README
	tar -czvf P3_FSE.tar.gz blink_led.c read_switch.c Makefile README

clean:	
	rm -f *~ *.o blink_led read_switch gpio_extra
