#include <bits/stdc++.h>
using namespace std;

int maxLenMap(vector<int>&A, int n)
{   
       unordered_map<int,int> map;
       int sum =0;
       int maxi =0;
       for(int i=0;i<n;i++){
           sum += A[i];
           if(sum == 0){
               maxi = max(maxi, i+1);
           }else{
               if(map.find(sum) != map.end()){
                   
                   maxi = max(maxi ,i - map[sum] );
               }else{
                   map[sum] =i;
               }
           }
       }
       return maxi;
}

int maxLenLoop(vector<int>&A, int n)
    {   
        int sum;
        int maxi = 0;
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum += A[j];
                if(sum == 0){
                   maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }

int main(){
    int n;
    cin >> n;
    vector<int> A;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        A.push_back(value);
    }
    int answer = maxLenMap(A,n);

    cout << answer << endl;
}