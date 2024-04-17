cc = g++
cpflags = -std=c++11 -Wall

srcs = $(wildcard *.cpp)
bins = $(patsubst %.cpp,%,$(srcs))

all: $(bins)

%: %.cpp
	$(cc) $(cppflags) $< -o $@

.PHONY: clean

clean:
	rm -f $(bins)
