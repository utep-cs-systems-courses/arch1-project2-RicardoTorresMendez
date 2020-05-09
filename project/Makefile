# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project.elf 

#additional rules for files
project.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o switches.o toolMain.o buzzer.o ../demos/timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project.elf
	mspdebug rf2500 "prog project.elf"

clean:
	rm -f *.o *.elf

