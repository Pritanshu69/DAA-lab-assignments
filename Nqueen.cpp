#include<iostream>

using namespace std;

#define N 8

bool isSafe(int board[N][N],int row, int col){
    int i,j;

    //NOTE - check this row on left side
    
    for(int i=0;i<col;i++){
        if(board[row][i])
        return false;
    }

    //NOTE - check upper diagonal on left side
    for(i=row,j=col;i>=0 && j>=0; i--,j--)
        if(board[i][j])
        return false;

    //NOTE - check lower diagonal on left side
    for(i=row,j=col;j+=0 && i<N; i++,j--)
        if(board[i][j])
        return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    if (col >= N)
        return true;

    for(int i=0; i<N; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1;

        if(solveNQUtil(board,col+1))
            return true;

        board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ() {
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // Print solution
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
    return true;
}

int main() {
    solveNQ();
    return 0;
}