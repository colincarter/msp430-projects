TARGET=main
CC=naken430asm
CFLAGS=-d -l main.lst
OBJS=main.s

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET).elf $(OBJS)
	mspdebug rf2500 "prog $(TARGET).elf"


clean:
	rm -fr $(TARGET).elf $(OBJS)
