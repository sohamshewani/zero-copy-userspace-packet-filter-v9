CC=gcc
CFLAGS=-Wall -Wextra -O2
SRCS=src/packet_receiver.c
OBJS=$(SRCS:.c=.o)
EXEC=zero-copy-userspace-packet-filter

all: $(EXEC)

$(EXEC): $(OBJS)	
gcc $(CFLAGS) -o $@ $^ -lpthread

%.o: %.c

gcc $(CFLAGS) -c -o $@ $<

install:
mkdir -p /usr/local/bin
install -m 755 $(EXEC) /usr/local/bin

uninstall:
rm -f /usr/local/bin/$(EXEC)

test: $(EXEC)
./$(EXEC) --test

integration-test: $(EXEC)
./$(EXEC) --integration-test
