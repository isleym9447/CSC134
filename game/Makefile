

# cd /workspaces/CSC134/game

# make        # compiles everything into "game"

# make clean  # deletes object files + the game executable

# ./game      # runs your program













# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Output program name
TARGET = game

# Source files (all .cpp files in this folder)
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
