

# make        # compiles everything into "game"
# ./game      # runs your program
# make clean  # deletes object files + the game executable











# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Output program name
TARGET = game

# Source files
SRCS = mainmenu.cpp charcreate.cpp
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
