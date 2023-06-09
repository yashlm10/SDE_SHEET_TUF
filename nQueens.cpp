#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>board,int n){
    int duprow = row;
    int dupcol = col;
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q')return false;

        row--;
        col--;
    }

    row = duprow;
    col = dupcol;
    while(col>=0){
        if(board[row][col] == 'Q')return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while(col>=0 && row < n){
        if(board[row][col] == 'Q')return false;
        col--;
        row++;
    }
    return true;
}

void placeQueens(int col, vector<vector<string>> &answer, vector<string>&board, int n){
    if(col == n){
        answer.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            placeQueens(col+1,answer,board,n);
            board[row][col] = '.';

        }
    }
}

vector<vector<string>> returnBoard(int n){
    vector<vector<string>> answer;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }
    placeQueens(0,answer,board,n);
    return answer;
}

void placeQueensOptimal(int col,vector<vector<string>> &answer,vector<string> board,int n, vector<int> &leftRow,vector<int> &lowerDiagonal, vector<int>&upperDiagonal){
    if(col == n){
        answer.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
            board[row][col] = 'Q';
            leftRow[row]= 1;
            lowerDiagonal[row+col] =1;
            upperDiagonal[n-1+col-row] =1;
            placeQueens(col+1,answer,board,n);
            board[row][col] = '.';
            leftRow[row]= 0;
            lowerDiagonal[row+col] =0;
            upperDiagonal[n-1+col-row] =0;
        }
    }

}

vector<vector<string>> returnBoardOptimal(int n){
    vector<vector<string>> answer;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }
    vector<int>leftRow(n,0), lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);
    placeQueensOptimal(0,answer,board,n, leftRow, lowerDiagonal, upperDiagonal);
    return answer;
}

int main(){
    int n;
    cin >>n;
    vector<vector<string>> ans = returnBoardOptimal(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}