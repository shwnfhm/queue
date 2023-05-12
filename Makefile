CC = gcc
CFLAGS = -O0 -g -Wall -Werror

all: qtest

qtest: qtest.o report.o console.o harness.o queue.o
	$(CC) $(CFLAGS) -o qtest qtest.o report.o console.o harness.o queue.o

queue.o: queue.c queue.h harness.h
	$(CC) $(CFLAGS) -c queue.c 

report.o: report.c
	$(CC) $(CFLAGS) -c report.c

console.o: console.c
	$(CC) $(CFLAGS) -c console.c

harness.o: harness.c
	$(CC) $(CFLAGS) -c harness.c

test: qtest driver.py
	chmod +x driver.py
	./driver.py

clean:
	rm -f *.o *~ qtest 
	rm -rf *.dSYM
	(cd traces; rm -f *~)

