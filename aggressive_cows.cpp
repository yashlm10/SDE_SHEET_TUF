#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&stalls,int n,int c,int d){
    int k = stalls[0];
    c--;
    for(int i = 1;i<n;i++){
        if(stalls[i]-k >= d){
           c--;
           if(!c){
            return true;
           }
           k = stalls[i];
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >>c;
        vector<int>stalls;
        for(int i=0;i<n;i++){
           int value;
           cin >> value;
           stalls.push_back(value);
        }
        sort(stalls.begin(),stalls.end());
        int maxi = stalls[n-1] - stalls[0];
        /*int ans = INT_MIN;
        for(int d=1;d<maxi;d++){
         bool possible = isPossible(stalls,n,c,d);
         if(possible){
            ans = max(ans,d);
         }
        }
        cout << ans;*/
        int lo = 1,hi = maxi;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            bool possible = isPossible(stalls, n, c, mid);
            if(possible) lo = mid+1;
            else hi = mid-1;
        }
        cout << hi << endl;
    }
return 0;
}