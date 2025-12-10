# ----------- COMPILER & PATHS --------------
CXX = C:/mingw64_sfml/bin/g++
SFML_INC = C:/Users/teaos/OneDrive/Desktop/school/SFML-2.6.2/include
SFML_LIB = C:/Users/teaos/OneDrive/Desktop/school/SFML-2.6.2/lib

INCLUDES = -Iinclude -I$(SFML_INC)
LIBS = -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS = -std=c++17 -Wall $(INCLUDES)

# ------------ SOURCE FILES -----------------
SRC = $(wildcard src/*.cpp src/ui/*.cpp src/scenes/*.cpp)
OBJ = $(SRC:.cpp=.o)

# ------------ OUTPUT EXECUTABLE ------------
TARGET = game.exe

# ------------ BUILD RULES ------------------
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(LIBS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ) $(TARGET) 2>NUL || echo clean
