# Generated by makegen....

TARGET = test-impunere
OBJECTS = test-impunere.o

CC = gcc
CFLAGS =   $(INCDIR)

LIBS = -lncurses
LIBDIR = -L/usr/lib
INCDIR = -I/usr/include

INSTALLDIR = 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBDIR) $(LIBS)

clean:
	rm -f a.out core *~ \#* *.bak $(TARGET) $(OBJECTS)

