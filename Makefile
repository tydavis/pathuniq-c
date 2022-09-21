.PHONY: pathuniq clean install all

OBJS =  pathuniq
CFLAGS = -Wall -O2

pathuniq: pathuniq.c
	$(CC) $(CFLAGS) -o pathuniq pathuniq.c

clean:
	rm -f pathuniq

install: pathuniq
	mkdir -p ~/.bin;
	mv ./pathuniq ~/.bin/;

all: pathuniq

