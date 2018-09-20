CC=gcc
CFLAGS=-I
DEPS=hellomake.h
OBJ=hellomake.o hellofun.o

all : hellomake

### % = wildcard: saying all <name>.o files use corresponding <name>.c files
### $@ refers to first element on right side of colon
### $< refers to entire right side of colon
### -c compile flag
### -o compiles into object files
%.o:%.c $(DEPS)
	$(cc) -c -o $@ $< $(CFLAGS)

hellomake : $(OBJ)
	$(CC) -o $@ $< $(CFLAGS)
