#include <bits/stdc++.h>
using namespace std;

    bool searchMatrixBinary(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m= matrix[0].size();
        int left = 0;
        int right = n*m-1;
        if(!n)return false;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(matrix[mid/m][mid%m] == target){
                return true;
            }else if(matrix[mid/m][mid%m] > target){
                right = mid -1;
            }else{
                left = mid +1;
            }
        }
        return false;
    }
    
    bool searchMatrixLinear(vector<vector<int>>& matrix, int target){

        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1;
        for(int i=0;i<n-1;i++){
            if(matrix[i][0]<=target && matrix[i+1][0]>target){
                row = i;
                break;
            }
        }
        bool found= 0;
        for(int i = 0;i<m;i++){
            if(matrix[row][i] == target){
            found = 1;}
           
        }
        return found;
    }
    
    int main(){
        int n,m;
        cin >> n >> m;
        int target;
        cin >> target;
        int value;
        vector<vector<int>> matrix;
        for(int i=0;i<n;i++){
           vector<int> row;
           for(int i=0;i<m;i++){
            cin >> value;
            row.push_back(value);
           }
           matrix.push_back(row);

        }
        if(searchMatrixBinary(matrix,target)){
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        }
        if(searchMatrixLinear(matrix,target)){
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        }
    }