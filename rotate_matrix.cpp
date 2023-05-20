#include <bits/stdc++.h>
using namespace std;

void rotate_array_clockwise(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
                
             swap(v[i][j],v[j][i]);
                
        }
    }

    for(int i=0;i<v.size();i++){
           reverse(v[i].begin(), v[i].end());
    }
}

int main(){
    int n;
    cin >> n;
    int value;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            cin >> value;
            row.push_back(value);
        }
        v.push_back(row);
    }
    rotate_array_clockwise(v);
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
          cout << v[j][i] << " ";
        }
    cout << endl;
    }
    
    return 0;
}