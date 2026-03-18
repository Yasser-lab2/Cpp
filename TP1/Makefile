CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2

TARGET = tp1
SRCS = main.cpp Rectangle.cpp RectanglePoints.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Point.h Rectangle.h RectanglePoints.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
