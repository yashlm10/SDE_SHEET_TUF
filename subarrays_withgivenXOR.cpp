#include <bits/stdc++.h>
using namespace std;

int subarraysXorMap(vector<int> &arr, int x)
{
   unordered_map<int,int> mpp;
   int cnt = 0;
   int xorr =0;
   mpp[0]++;
   for(int i=0;i< arr.size();i++){
       xorr ^= arr[i];
       int z = xorr ^ x;

    
        cnt += mpp[z];
    
        mpp[xorr]++;
   }
   return cnt;
}

int subarraysXorLoops(vector<int> &arr, int x)
{
    int xorr;
    int cnt =0;
   for(int i=0;i<arr.size();i++){
       xorr =0;
       for(int j=i;j<arr.size();j++){
           xorr ^= arr[j];
           if(xorr == x)cnt++;

       }
   }
   return cnt;
}

int main(){
    int n,t;
    cin >> n >> t;
    int value;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin >> value;
        arr.push_back(value);
    }

    int answer = subarraysXorMap(arr,t);

    cout << answer << endl;
}