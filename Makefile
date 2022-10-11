#################################################################
# File: Makefile
# ################################################################
#
CC=g++
LDFLAGS=$(shell prk-config --libs opencv4)
CFLAGS=-Wall -Werror `pkg-config --cflags opencv4`
SOURCES=$(wildcard *.cpp)
INCLUDES=$(wildcard *.hpp)
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=output

all:$(TARGET)

$(TARGET):$(OBJECTS)
        $(CC) -o $@ $(CPPFLAGS) $^ $(SOURCES)

%.o : %.c %.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
