CC=g++
CFLAGS=-c -Wall -I./../inc/ -DDEBUG_MODE
LDFLAGS=
SOURCES=test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test
LIBS=-L../out/ -lprac
OBJDIR=./../out
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(OBJDIR)/$@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o
	-rm -f test
