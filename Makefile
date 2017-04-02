CC = gcc
CFLAGS = -c -Wall
LFLAGS = -Wall
LIBS = -lm -lncurses

all: main.o functions.o ui.o
	$(CC) $(LFLAGS) -o main main.c functions.c ui.c linear.c binary.c $(LIBS)

main.o: main.c main.h
	$(CC) $(CFLAGS) main.c $(LIBS)

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) functions.c $(LIBS)

ui.o: ui.c ui.h
	$(CC) $(CFLAGS) ui.c $(LIBS)

linear.o: linear.c linear.h
	$(CC) $(CFLAGS) linear.c $(LIBS)

binary.o: binary.c binary.h
	$(CC) $(CFLAGS) binary.c $(LIBS)

run:
	./main

clean:
	rm -f *.o main a.out