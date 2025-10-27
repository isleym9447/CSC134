#include <iostream>
#include <vector>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

const int BOARD_SIZE = 10;

// Define ship types and lengths
struct Ship {
    char symbol;
    int length;
};

// Fleet of ships
vector<Ship> ships = {
    {'A', 5},  // Aircraft Carrier
    {'B', 4},  // Battleship
    {'C', 3},  // Cruiser
    {'D', 3},  // Destroyer
    {'S', 2}   // Submarine
};

// Function prototypes
void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board, bool hideShips = false);
bool placeShip(vector<vector<char>>& board, int x, int y, int length, char symbol, bool horizontal);
void placeAllShipsRandomly(vector<vector<char>>& board);
bool makeGuess(vector<vector<char>>& board, int x, int y);
bool allShipsSunk(const vector<vector<char>>& board);
pair<int, int> getRandomMove(const vector<vector<char>>& board);

// Initialize the board
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            board[i][j] = '~';
}

// Display the board
void displayBoard(const vector<vector<char>>& board, bool hideShips) {
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; ++i) cout << i << " ";
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            char c = board[i][j];
            if (hideShips && c != '~' && c != 'X' && c != 'O')
                cout << "~ ";
            else
                cout << c << " ";
        }
        cout << endl;
    }
}

// Place a single ship (returns true if successful)
bool placeShip(vector<vector<char>>& board, int x, int y, int length, char symbol, bool horizontal) {
    if (horizontal) {
        if (y + length > BOARD_SIZE) return false;
        for (int i = 0; i < length; ++i)
            if (board[x][y + i] != '~') return false;
        for (int i = 0; i < length; ++i)
            board[x][y + i] = symbol;
    } else {
        if (x + length > BOARD_SIZE) return false;
        for (int i = 0; i < length; ++i)
            if (board[x + i][y] != '~') return false;
        for (int i = 0; i < length; ++i)
            board[x + i][y] = symbol;
    }
    return true;
}

// Place all ships randomly on a board (guaranteed to succeed)
void placeAllShipsRandomly(vector<vector<char>>& board) {
    bool success = false;

    while (!success) {
        initializeBoard(board);  // clear the board
        success = true;

        for (const Ship& ship : ships) {
            bool placed = false;
            int attempts = 0;

            while (!placed && attempts < 200) {  // Try up to 200 random placements
                int x = rand() % BOARD_SIZE;
                int y = rand() % BOARD_SIZE;
                bool horizontal = rand() % 2;
                placed = placeShip(board, x, y, ship.length, ship.symbol, horizontal);
                attempts++;
            }

            if (!placed) {
                success = false;  // Restart placement for all ships if one fails
                break;
            }
        }
    }
}

// Make a guess
bool makeGuess(vector<vector<char>>& board, int x, int y) {
    if (board[x][y] == '~') {
        board[x][y] = 'O'; // Miss
        return false;
    } else if (board[x][y] != 'O' && board[x][y] != 'X') {
        board[x][y] = 'X'; // Hit
        return true;
    }
    return false; // Already guessed
}

// Check if all ships are sunk
bool allShipsSunk(const vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (board[i][j] != '~' && board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Get a random move for AI
pair<int, int> getRandomMove(const vector<vector<char>>& board) {
    int x, y;
    do {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
    } while (board[x][y] == 'O' || board[x][y] == 'X'); // avoid repeats
    return {x, y};
}

// Main game loop
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    vector<vector<char>> playerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE));
    vector<vector<char>> enemyBoard(BOARD_SIZE, vector<char>(BOARD_SIZE));

    initializeBoard(playerBoard);
    initializeBoard(enemyBoard);

    // Randomly place ships for both player and enemy
    placeAllShipsRandomly(playerBoard);
    placeAllShipsRandomly(enemyBoard);

    cout << "🚢 Welcome to Battleship! 🚢\n";
    cout << "Your ships and the enemy's ships have been placed randomly.\n";

    bool gameRunning = true;
    while (gameRunning) {
        cout << "\nYOUR BOARD:\n";
        displayBoard(playerBoard, false);

        cout << "\nENEMY BOARD:\n";
        displayBoard(enemyBoard, true);  // hides enemy ships

        // Player attacks
        int x, y;
        cout << "\nEnter attack coordinates (row col): ";
        cin >> x >> y;

        if (cin.fail() || x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid coordinates. Try again.\n";
            continue;
        }

        bool hit = makeGuess(enemyBoard, x, y);
        if (hit)
            cout << "🔥 You hit an enemy ship!\n";
        else
            cout << "💦 You missed!\n";

        if (allShipsSunk(enemyBoard)) {
            cout << "\n🎉 You win! All enemy ships are sunk!\n";
            break;
        }

        // Enemy turn
        cout << "\nEnemy is attacking...\n";
        pair<int, int> move = getRandomMove(playerBoard);
        bool enemyHit = makeGuess(playerBoard, move.first, move.second);
        cout << "Enemy attacked (" << move.first << ", " << move.second << ") -> "
             << (enemyHit ? "Hit!" : "Miss.") << "\n";

        if (allShipsSunk(playerBoard)) {
            cout << "\n💀 Game Over! The enemy sunk all your ships.\n";
            break;
        }
    }

    cout << "\nThanks for playing Battleship!\n";
    return 0;
}
