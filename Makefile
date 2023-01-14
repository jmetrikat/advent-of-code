CC = clang
CFLAGS = -g -Og -Wall -Weverything # -pedantic
SANITIZER = -fsanitize=address -fsanitize=undefined # -fsanitize=leak

SRC = $(shell find . -name '*.c' -print)
OBJ = $(shell find . -name '*.o' -print)
DSYM = $(shell find . -name '*.dSYM' -print)
TRG = $(SRC:%.c=%)

all: $(TRG)

%: %.c
	$(CC) -c $< $(CFLAGS) -o $@.o $(SANITIZER)
	$(CC) $@.o $(CFLAGS) -o $@ $(SANITIZER)
	@rm -f $(OBJ)

clean:
	@rm -f $(TRG)
	@rm -f $(OBJ)

.PHONY: all clean
