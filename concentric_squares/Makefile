CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

SRCS := $(wildcard *.cpp)
EXES := $(SRCS:.cpp=.exe)

all: $(EXES)

%.exe: %.cpp
	@echo "Compiling $< -> $@"
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXES)
