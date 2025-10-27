CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra

SRC := main.cpp intro.cpp ending.cpp oracle.cpp \
	asphodel.cpp asphodel_events.cpp \
	elysium.cpp elysium_events.cpp \
	tartarus.cpp tartarus_events.cpp

OBJ := $(SRC:.cpp=.o)
BIN := EscapeFromTheUnderworld

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(BIN)