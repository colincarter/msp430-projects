TARGET=main
CC=msp430-gcc
CFLAGS=-D_GNU_ASSEMBLER_ # -Wa,-ahlms=myfile-asm.lst
OBJS=main.o

all: $(TARGET).elf
	msp430-objdump -DS main.elf > main-asm.lst
	msp430-size --target=elf32-msp430 main.elf
	mspdebug rf2500 "prog $(TARGET).elf"

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) -o main.elf $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(TARGET).elf $(OBJS) main-asm.lst
