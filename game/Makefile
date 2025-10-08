# ==========================================================
# Cyberpunk 2077 Mini Game - Makefile
# CSC 134 - Mattea Isley
# ----------------------------------------------------------
# Commands:
#   make        → Compiles everything into "game"
#   make clean  → Deletes object files + executable
#   ./game      → Runs your program
# ==========================================================

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -I . -I scenes -I locations_and_gigs -I character_images
    # include subfolder + root

# Output program name
TARGET = game

# Source files (all .cpp files in this folder + subfolders)
# Source files (all .cpp files in this folder + subfolders)
SRCS = $(wildcard *.cpp scenes/*.cpp locations_and_gigs/*.cpp)
OBJS = $(SRCS:.cpp=.o)


# ==========================================================
# Default target
# ==========================================================
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	@echo ">>> Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo ">>> Build complete! Run with ./$(TARGET)"

# ==========================================================
# Compile each .cpp into .o
# ==========================================================
%.o: %.cpp
	@echo ">>> Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==========================================================
# Clean up build files
# ==========================================================
clean:
	@echo ">>> Cleaning up object files and executable..."
	rm -f $(OBJS) $(TARGET)
	@echo ">>> Cleanup complete."

# ==========================================================
# (Optional) Run command for convenience
# ==========================================================
run: all
	@./$(TARGET)
