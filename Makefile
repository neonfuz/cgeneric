
main: *.c types/*.h
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm main

.PHONY: clean

