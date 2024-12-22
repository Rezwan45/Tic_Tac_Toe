#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void computerMove(char board[SIZE][SIZE]);
int isValidMove(char board[SIZE][SIZE], int row, int col);

int main() {
    char board[SIZE][SIZE];
    char playerName[50];
    int winner = 0, moves = 0;

    // Welcome message
    printf("****************\n");
    printf("Tic Tac Toe\nCOMP 2130 - Fall 2024\n");
    printf("You will be playing against the computer\n");
    printf("***************n");
    printf("What is your name?\n");
    scanf("%s", playerName);
    printf("Hello %s ... Let's have fun !!! You = X | Computer = O\n", playerName);

    // Initialize and print the board
    initializeBoard(board);
    printBoard(board);

    // Game loop
    while (moves < SIZE * SIZE && winner == 0) {
        playerMove(board);
        moves++;
        printBoard(board);
        winner = checkWinner(board);
        if (winner != 0 || moves == SIZE * SIZE) break;

        computerMove(board);
        moves++;
        printBoard(board);
        winner = checkWinner(board);
    }

    // Determine the result
    if (winner == 1) {
        printf("*******\nYou won!\n*******\n");
    } else if (winner == -1) {
        printf("*******\nComputer won!\n*******\n");
    } else {
        printf("*******\nIt's a draw!\n*******\n");
    }

    return 0;
}

// Function to initialize the board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check for a winner
int checkWinner(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') return 1;
            if (board[i][0] == 'O') return -1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') return 1;
            if (board[0][i] == 'O') return -1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') return 1;
        if (board[0][0] == 'O') return -1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') return 1;
        if (board[0][2] == 'O') return -1;
    }
    return 0; // No winner yet
}

// Function for the player's move
void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    printf("Enter X,Y coordinates for your move (1-3 for both): ");
    scanf("%d,%d", &row, &col);
    row--; col--; // Adjust for 0-based indexing

    while (!isValidMove(board, row, col)) {
        printf("Invalid move! Try again: ");
        scanf("%d,%d", &row, &col);
        row--; col--; // Adjust for 0-based indexing
    }
    board[row][col] = 'X';
}

// Function for the computer's move (simple AI - picks first available spot)
void computerMove(char board[SIZE][SIZE]) {
    int row, col;
    printf("Computer's move:\n");
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = 'O';
                return;
            }
        }
    }
}

// Function to validate the move
int isValidMove(char board[SIZE][SIZE], int row, int col) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        return 1;
    }
    return 0;
}
