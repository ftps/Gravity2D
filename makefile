TARGET = exe
CC = g++
LIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system
HEAD = ./Headers
SRCS = ./Sources
INCDIR = -I$(HEAD)
CFLAGS = -Wall -std=c++17 -funroll-loops $(INCDIR)
.PHONY: clean

DEPS = $(wildcard $(HEAD)/*.hpp)
OBJS = $(patsubst %.cpp, %.o, $(wildcard $(SRCS)/*.cpp))

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	-rm -r $(SRCS)/*.o
	-rm -r $(TARGET)

