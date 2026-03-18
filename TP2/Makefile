CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2

TARGET = tp2
SRCS = main.cpp Point.cpp Forme.cpp Triangle.cpp Quadri.cpp Cercle.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Point.h Forme.h Triangle.h Quadri.h Cercle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
