# makefile configuration
COMMON_OBJECTS		= robomania.o wdt_handler.o p2_interrupt_handler.o draw_shapes.o switches.o wdt_c_handler.o buzzer.o draw_ship.o state_machines.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: robomania.elf robomania_s.elf

#additional rules for files
robomania.elf: ${COMMON_OBJECTS} switch_state.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd
robomania_s.elf: ${COMMON_OBJECTS} switch_state_s.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: robomania.elf
	msp430loader.sh $^
load_s: robomania_s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

robomania.o: state_machines.h

wdt_handler.o: state_machines.h

p2_interrupt_handler.o: switches.h

draw_shapes.o: draw_shapes.h

state_machines.o: state_machines.h

switches.o: switches.h

wdt_handler.o: state_machines.h

wdt_c_handler.o: state_machines.h

buzzer.o: buzzer.h

draw_ship.o: state_machines.h

switch_state.o: switch_state.c state_machines.h

switch_state_s.o: switch_state_s.s draw_shapes.h switches.h state_machines.h
