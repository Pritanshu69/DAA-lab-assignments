#include<iostream>
using namespace std;

int MAX_N = 10;

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N){
    //NOTE - check weather the queen is in the same column or not
    for(int i = 0; i < row; ++i){                       
            if(board[i][col]== 1){
                return false;
            }
    }
//NOTE - Now check for left diagonal 
    for(int i=row,j=col;i>=0 && j>=0 ; --i,--j){
        if(board[i][j]==1){
            return false;
        }
    }
//NOTE - Now check for right diagonal
    for(int i=row,j=col;i>=0 && j<N; --i,++j){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
