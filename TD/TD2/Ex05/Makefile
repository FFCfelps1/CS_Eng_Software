CXX ?= C:/msys64/ucrt64/bin/g++.exe

CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = listeTest

SRC = test/listeTest.cpp src/liste.cpp

LDFLAGS = -lgtest -lgtest_main -pthread

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all test clean
