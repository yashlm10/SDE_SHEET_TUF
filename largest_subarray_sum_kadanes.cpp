#include <bits/stdc++.h>
using namespace std;

int largest_subarray_sum_mysol(vector<int> &v, int n){
    
    for(int i=0;i<(n/2);i++){
        if(v[i]>=0 && v[i]+v[i+1] >=0){
            v[i+1] += v[i];
        }
        if(v[n-1-i]>=0 && v[n-1-i]+v[n-2-i] >=0){
            v[n-2-i] += v[n-1-i];
        }
    }
   if(v[n/2]>=0)
     return v[n/2];
   else
     return 0;
}

void printLargestSumSubarray(vector<int>&u, int ansStart, int ansEnd){
   
   for(int i=ansStart;i<=ansEnd;i++){
    cout << u[i] << " ";
   }
   cout << endl;
}

void lss_kadanesalgo(vector<int> &u, int n){
    long long maxi = LONG_MIN;
    long long sum = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int start = -1;
    bool check = 0;
    for(int i=0;i<n;i++){
        if(sum == 0) start = i;
        sum += u[i];
        
        if(sum > maxi){
            maxi = sum;
            ansEnd= i;
            ansStart = start;
        }
        if(sum < 0 ){
            sum = 0;
            
        }
    }
    if(maxi<0){
        cout << 0 << endl;
        check =1;
    }else{
        cout << maxi << endl;
    }
    if(!check)
    printLargestSumSubarray(u,ansStart, ansEnd);
    
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        v.push_back(value);
    }
    vector<int>u = v;
    int ans = largest_subarray_sum_mysol(v,n);
    cout << ans << endl;
    lss_kadanesalgo(u,n);
   
    return 0;
}