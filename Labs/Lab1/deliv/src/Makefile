CC=g++
CFLAGS=-c -o
LDFLAGS=
_DEPS=hellomake.c
DEPS=$(patsubst %, $(IDIR)/%.$(DEPS))
ODIR=obj
_OBJ=hellomake.o hellofun.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
    $(CC) $(CFLAGS) $< -o $@
