#include <bits/stdc++.h>
using namespace std;

    int uniquePathsCombi(int m, int n) {
        double ans=1;
        for(int i=1;i<=n-1;i++){
            ans *= (m-1 + i);
            ans /= (i);
        }
        return (int)ans;
    }


    int countPathsRecurr(int i,int j,int m,int n){
        if(i==m-1 && j==n-1) return 1;
        else if(i>m-1 || j>n-1) return 0;
        else return countPathsRecurr(i+1,j,m,n)+countPathsRecurr(i,j+1,m,n);
    }
    int uniquePathsRecurr(int m, int n) {
        return countPathsRecurr(0,0,m,n);
    }




    int countPathsDp(int i,int j,int m,int n, vector<vector<int>> &dp){
        

        if(i==(m-1) && j==(n-1)) return 1;
        if(i>m-1 || j>n-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = countPathsDp(i+1,j,m,n,dp)+countPathsDp(i,j+1,m,n,dp);
    }
    int uniquePathsDp(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        int nums = countPathsDp(0,0,m,n,dp);
        if(m==1 && n==1){
            return nums;
        }
        return dp[0][0];
    }

int main(){
    int n,m;
    cin >>m>>n;
    int pathsCombi = uniquePathsCombi(m,n);
    int pathsRecurr = uniquePathsRecurr(m,n);
    int pathsDp = uniquePathsDp(m,n);

    cout<< pathsCombi << " " << pathsDp<< " " << pathsRecurr << endl;
    return 0;
}