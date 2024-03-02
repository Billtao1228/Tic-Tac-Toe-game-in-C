#include <stdio.h>

#define SIZE 3 // Define the size of the Tic-Tac-Toe board

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkTie(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], char player);
void switchPlayer(char *player);

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int gameEnd = 0;

    initializeBoard(board); // Initialize the game board

    while (!gameEnd) {
        printBoard(board); // Display the current state of the board
        makeMove(board, currentPlayer); // Prompt the current player to make a move
        
        if (checkWin(board)) {
            gameEnd = 1;
            printf("Player %c wins!\n", currentPlayer);
        } else if (checkTie(board)) {
            gameEnd = 1;
            printf("It's a tie!\n");
        }

        if (!gameEnd) {
            switchPlayer(&currentPlayer); // Switch turns between players
        }
    }

    return 0;
}

// Initialize the game board with spaces (' ')
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the current state of the board
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("-----\n");
    }
}

// Check if there's a win condition on the board
int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;
    return 0;
}

// Check if the game is a tie (no empty spaces left)
int checkTie(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Prompt the current player to make a move
void makeMove(char board[SIZE][SIZE], char player) {
    int row, col;
    do {
        printf("Player %c, enter row and column to place your %c (0-2 0-2): ", player, player);
        scanf("%d%d", &row, &col);
    } while (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ');
    board[row][col] = player;
}

// Switch the current player from 'X' to 'O', or 'O' to 'X'
void switchPlayer(char *player) {
    *player = (*player == 'X') ? 'O' : 'X';
}
