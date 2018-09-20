#likely some errors

IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)
ODIR=obj
LDIR=../lib
LIBS=-lm
_DEPS=project.c
DEPS=$(patsubst %, $(IDIR)/%.$(DEPS))
_OBJ=hellomake.o hellofun.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

all : project

$(ODIR)/%.o: %.c $(DEPS)
	$(cc) -c -o $@ $< $(CFLAGS)

project : $(OBJ)
	$(cc) -o $@ $^ $(CFLAGS) $(LIBS)

#dummy : means that if a file is ever made named clean, delete it
.PHONY : clean

clean :
	rm -f $(ODIR)/*.o *~core $(IDIR)/*~
