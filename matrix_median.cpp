#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    int row = A.size();
    int column = A[0].size();
    int median = (row*column)/2 + 1;
    
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<row;i++){
        if(A[i][0] < mini) mini = A[i][0];
        if(A[i][column-1] > maxi) maxi = A[i][column-1];
    }
    
    while(mini < maxi){
        int mid = (maxi+mini)/2;
        int cnt =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(A[i][j] <= mid)cnt++;
            }
        }
        
        if(cnt >= median) maxi = mid;
        else mini = mid+1;
    }
    return mini;
}

int main(){
    vector<vector<int>> A;
    int row,col;
    cin >> row >> col;
    for(int i=0;i<row;i++){
        vector<int>temp;
        for(int j=0;j<col;j++){
            int value;
            cin >> value;
            temp.push_back(value);
        }
        A.push_back(temp);
    }
    int ans = findMedian(A);
    cout << ans << endl;
    return 0;
}