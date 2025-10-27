
#include <iostream>
#include <vector>
using namespace std;

const int BOARD_SIZE = 10;

// Function prototypes
void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool placeShip(vector<vector<char>>& board, int x, int y, int length, char symbol, bool horizontal);
bool makeGuess(vector<vector<char>>& opponentBoard, int x, int y);

// Initialize the board with '~'
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '~';
        }
    }
}

// Display the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; ++i) cout << i << " ";
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Place a ship
bool placeShip(vector<vector<char>>& board, int x, int y, int length, char symbol, bool horizontal) {
    if (horizontal) {
        if (y + length > BOARD_SIZE) return false;
        for (int i = 0; i < length; ++i) if (board[x][y + i] != '~') return false;
        for (int i = 0; i < length; ++i) board[x][y + i] = symbol;
    } else {
        if (x + length > BOARD_SIZE) return false;
        for (int i = 0; i < length; ++i) if (board[x + i][y] != '~') return false;
        for (int i = 0; i < length; ++i) board[x + i][y] = symbol;
    }
    return true;
}

// Guess a position
bool makeGuess(vector<vector<char>>& opponentBoard, int x, int y) {
    if (opponentBoard[x][y] == '~') {
        opponentBoard[x][y] = 'O'; // Miss
        return false;
    } else if (opponentBoard[x][y] != 'O' && opponentBoard[x][y] != 'X') {
        opponentBoard[x][y] = 'X'; // Hit
        return true;
    }
    return false; // Already guessed
}

// Main function
int main() {
    vector<vector<char>> playerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE));
    vector<vector<char>> enemyBoard(BOARD_SIZE, vector<char>(BOARD_SIZE));

    initializeBoard(playerBoard);
    initializeBoard(enemyBoard);

    // Example: manually place ships (later, add user input)
    placeShip(playerBoard, 1, 1, 3, 'C', true);
    placeShip(enemyBoard, 4, 4, 3, 'C', false);

    bool gameRunning = true;
    while (gameRunning) {
        cout << "\nYour Board:\n";
        displayBoard(playerBoard);

        cout << "\nEnemy Board (hidden for now):\n";
        displayBoard(enemyBoard);

        int x, y;
        cout << "\nEnter coordinates to attack (row col): ";
        cin >> x >> y;

        if (makeGuess(enemyBoard, x, y))
            cout << "Hit!\n";
        else
            cout << "Miss!\n";

        // TODO: Add win check + enemy AI later
    }

    return 0;
}
