#################################################################
# File: Makefile
# ################################################################

CC=g++
LDFLAGS=$(shell pkg-config --libs opencv4)
CPPFLAGS=-Werror `pkg-config --cflags opencv4`
SOURCES=$(wildcard *.cpp)
INCLUDES=$(wildcard *.hpp)
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=output

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) -o $@ $(CPPFLAGS) $^ $(LDFLAGS)

%.o : %.c %.cpp
	$(CC) -c $(CPPFLAGS) $<
clean:
	rm -f $(TARGET) $(OBJECTS)
