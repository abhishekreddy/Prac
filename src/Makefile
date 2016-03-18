CC=g++
CFLAGS=-c -Wall -I./../inc/ -fPIC -g -DDEBUG_MODE -ggdb -Werror
LDFLAGS=-shared
SOURCES=slist.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=libprac.so
OBJDIR=./../out
OBJ=$(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(wildcard *.cpp)))

.PHONY: all clean

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJ) 
	$(CC) $(LDFLAGS) -o $(OBJDIR)/$@ $^

clean:
	-rm -f $(TARGET) $(wildcard *.o)
	-rm -rf $(OBJDIR)

