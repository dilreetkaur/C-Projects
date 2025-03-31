#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    system("cls");  // Clears the screen (for Windows)
    cout << "===== Tic-Tac-Toe =====\n\n";
    cout << "Player 1: X  |  Player 2: O\n\n";
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << endl;
}

bool isValidMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    return board[row][col] != 'X' && board[row][col] != 'O';
}

void makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    board[row][col] = currentMarker;
}

bool checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void playGame() {
    int position;
    while (true) {
        drawBoard();
        cout << "Player " << currentPlayer << "'s turn (" << currentMarker << "). Enter position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9 || !isValidMove(position)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        makeMove(position);

        if (checkWinner()) {
            drawBoard();
            cout << "?? Player " << currentPlayer << " wins! ??\n";
            break;
        }

        if (isBoardFull()) {
            drawBoard();
            cout << "It's a draw! ??\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    currentPlayer = 1;
    currentMarker = 'X';

    playGame();

    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        // Reset the board and restart
        char resetBoard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = resetBoard[i][j];

        main();  // Restart game
    }

    cout << "Thanks for playing! ??\n";
    return 0;
}

