CC=gcc
COPTS=-Wall -I./

OBJS = 	main.o	miastruct.o

DEPS = miastruct.h

BINS = main.elf

.PHONY: clean all

all: $(BINS)

%.o: %.c 
	$(CC) $(COPTS) $< -c -o $@

<<<<<<< Updated upstream
main.elf: $(OBJS)  
=======
main.elf: $(OBJS) 
>>>>>>> Stashed changes
	$(CC) $(COPTS) $^ -o $@

clean:
	rm -rf *.o $(BINS)
