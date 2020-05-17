
vpath %.c src

CC       := gcc
CFLAGS   := -std=c17 -Wall -Wextra -Wpedantic -g -O0
CPPFLAGS := -Iinclude
LDFLAGS  := 
LIBS     := 

OBJS     := $(patsubst %.c,%.o,$(notdir $(wildcard src/*.c)))
TARGET   := ork

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -f *.o $(TARGET)

