#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &A, int mid, int B){
    int cnt = 0,temp = 0;
    for(int i=0;i<A.size();i++){
        if(temp + A[i] > mid){
            cnt++;
            temp = A[i];
            if(temp > mid)return false;
        }else{
            temp += A[i];
        }
    }
    if(cnt < B)return true;
    else return false;
    
}

int books(vector<int> &A, int B) {
    if(B>A.size())return -1;
    
    int n = A.size();
    int mini = INT_MAX;
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(A[i] < mini) mini = A[i];
    }
    int lo = mini,hi = sum;
  
    while(lo <= hi){
        int mid = (lo + hi)/2;
        
        if(!isPossible(A,mid,B)){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
        
    }
    return lo;
}

int main(){
    int n,B;
    cin >>n >> B;
    vector<int> A;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        A.push_back(value);
    }

    int answer = books(A,B);
    cout << answer << endl;
    return 0;
}