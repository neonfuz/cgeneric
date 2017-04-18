
main: *.c
	$(CC) $(CFLAGS) -o main main.c *.c

clean:
	rm main

.PHONY: clean

