SRC  = ass.o main.o state_machine.o timer.o switches.o buzzer.o led.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS = ../demos/lib/libTimer.a -L/opt/ti/msp430_gcc/include

# Switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all:arch_project_2.elf

# Additional rules for files
arch_project_2.elf: ${SRC} ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: arch_project_2.elf
	msp430loader.sh arch_project_2.elf


clean:
	rm -f *.o *.elf

