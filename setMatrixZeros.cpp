#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZerosBetter(vector<vector<int>> &matrix, int n, int m){
    int row[n] = {0};
    int col[m] = {0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j]= 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;

}

vector<vector<int>> setMatrixZerosOptimal(vector<vector<int>> &matrix, int n, int m){
    int col0 = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                if(j != 0){
                   matrix[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
            }
            
        }
    }
     if(matrix[0][0] == 0){
       for(int i=0;i<m;i++){
            matrix[0][i]=0;
        }
   }
   if(col0 == 0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
  

return matrix;

}

int main(){
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> matrix;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<m;j++){
            int value;
            cin >> value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    

    vector<vector<int>> matrix1 = setMatrixZerosBetter(matrix,n,m);
    vector<vector<int>> matrix2 = setMatrixZerosOptimal(matrix,n,m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}