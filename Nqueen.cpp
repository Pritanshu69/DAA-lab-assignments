#include <iostream>

using namespace std;

const int MAX_N = 10; // Adjust the maximum value of N as per your requirement

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(int board[MAX_N][MAX_N], int row, int N) {
    if (row == N)
        return true;

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            if (solveNQueensUtil(board, row + 1, N))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N) {
    int board[MAX_N][MAX_N] = {0};

    if (solveNQueensUtil(board, 0, N)) {
        // Print the solution
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
