CC := g++
CFLAGS := -std=c++11

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.out,$(SRCS))

all: $(OBJS)
%.out: %.cpp
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(TARGET) *.out
	
.PHONY: all clean