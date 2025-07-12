CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

SRCS = main.cpp Corretor.cpp Cliente.cpp Imovel.cpp
TARGET = imobiliaria

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
