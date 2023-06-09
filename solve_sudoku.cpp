#include <bits/stdc++.h>
using namespace std;

bool isValid(int row,int col,char c,vector<vector<char>> &board){
    for(int i=0;i<9;i++){
        if(board[row][i] == c)return false;
        if(board[i][col] == c)return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == '.'){
                for(char c = '1';c<='9';c++){
                    if(isValid(i,j,c,board)){
                        board[i][j] = c;
                        if(solveSudoku(board)) return true;
                        board[i][j] = '.';

                    }
                   
                }
                 return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board;
   for(int i=0;i<9;i++){
     vector<char>row;
     for(int j=0;j<9;j++){
        char c;
        cin >> c;
        row.push_back(c);
     }
     board.push_back(row);
   }

   solveSudoku(board);
   
   for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cout<< board[i][j] << " ";
    }
    cout<<endl;
   }


}