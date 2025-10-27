CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra

SRC := main.cpp intro.cpp ending.cpp oracle.cpp \
       Asphodel.cpp asphodel_events.cpp \
       Elysium.cpp elysium_events.cpp \
       Tartarus.cpp tartarus_events.cpp

OBJ := $(SRC:.cpp=.o)
BIN := hades_game

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(BIN)