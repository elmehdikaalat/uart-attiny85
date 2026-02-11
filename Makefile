CC = avr-gcc
CFLAGS = -mmcu=attiny85 -DF_CPU=1000000UL -Os
LFLAGS =
EXE = main

C_SRCS = main.c
OBJ_FILES = $(C_SRCS:.c=.o)

.PHONY: clean flash

$(EXE).elf : $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

clean:
	rm -f *.o *.elf *.hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(EXE).hex: $(EXE).elf
	avr-objcopy -O ihex $(EXE).elf $(EXE).hex

flash: $(EXE).hex
	avrdude -c avrisp -p attiny85 -b 19200 -P /dev/ttyACM0 -U flash:w:$(EXE).hex:i
