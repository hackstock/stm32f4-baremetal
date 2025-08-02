CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -Wall  -mcpu=$(MACH) -mthumb --std=gnu11 -O0
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=firmware.map

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

startup.o:startup.c
	$(CC) $(CFLAGS) -o $@ $^

firmware.elf:startup.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.map