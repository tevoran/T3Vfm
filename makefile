CC := gcc
CC_FLAGS := -lX11 -o t3vwm

SRC := $(wildcard src/*.c)

main: $(SRC)
	$(CC) $(CC_FLAGS) $(SRC)