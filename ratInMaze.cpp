#include <bits/stdc++.h>
using namespace std;

void pathShorter(int row,int col,vector<string>&answer, string s, vector<vector<int>>&m, int n, vector<vector<int>>&visited,int di[], int dj[]){
        if(row == n-1 && col == n-1){
            answer.push_back(s);
            return;
        }
       
        string dir = "DLRU";
        for(int z=0;z<4;z++){
            if(row+ di[z] <n && row+di[z] >= 0 && col+ dj[z] < n && col+dj[z] >=0 && !visited[row+di[z]][col+dj[z]] && m[row+di[z]][col+dj[z]] ){
                 visited[row][col] = 1;
                 pathShorter(row+di[z],col+dj[z],answer,s + dir[z],m,n,visited,di,dj);
                 visited[row][col] = 0;
            }
        }
        
}

vector<string> findPathShorter(vector<vector<int>> &m, int n) {
        vector<string> answer;
        int di[] = {+1,0,0,-1};
        int dj[] = {0,-1,+1,0};
            
        vector<vector<int>> visited(n, vector<int>(n,0));
        if(m[0][0] == 1)pathShorter(0,0,answer,"",m,n,visited,di,dj);
        return answer;
}

void path(int row,int col,vector<string>&answer, string s, vector<vector<int>>&m, int n, vector<vector<int>>&visited){
        if(row == n-1 && col == n-1){
            answer.push_back(s);
            return;
        }
        if(row+1<n && !visited[row+1][col] && m[row+1][col]){
            visited[row][col] = 1;
            path(row+1,col,answer,s + 'D',m,n,visited);
            visited[row][col] = 0;
        }
        if(row-1>=0 && !visited[row-1][col] && m[row-1][col]){
            visited[row][col] = 1;
            path(row-1,col,answer,s + 'U',m,n,visited);
            visited[row][col] = 0;
        }
        if(col-1>=0 && !visited[row][col-1] && m[row][col-1]){
            visited[row][col] = 1;
            path(row,col-1,answer,s + 'L',m,n,visited);
            visited[row][col] = 0;
        }
        if(col+1<n && !visited[row][col+1] && m[row][col+1]){
            visited[row][col] = 1;
            path(row,col+1,answer,s + 'R',m,n,visited);
            visited[row][col] = 0;
        }
        
}

vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> answer;
        
        vector<vector<int>> visited(n, vector<int>(n,0));
        if(m[0][0] == 1)path(0,0,answer,"",m,n,visited);
        return answer;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> m;
    for(int i=0;i<n;i++){
        vector<int>row;
        for(int j=0;j<n;j++){
            int block;
            cin >> block;
            row.push_back(block);
        }
        m.push_back(row);
    }
    vector<string> answer = findPath(m,n);
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    }
    return 0;
}