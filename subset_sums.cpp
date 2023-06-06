#include <bits/stdc++.h>
using namespace std;

void addSums(int ind, vector<int>&arr, int n, vector<int> &ans, int sum){
    if(ind == n){
        ans.push_back(sum);
        return;
    }

    addSums(ind+1,arr,n,ans,sum+arr[ind]);
    addSums(ind+1,arr,n,ans,sum);
}

vector<int> subsetSum(vector<int>arr, int n){
    vector<int> ans;
    addSums(0, arr , n , ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int j;
        cin >> j;
        arr.push_back(j);
    }
    vector<int> answer = subsetSum(arr,n);
    for(int i=0;i<answer.size();i++){
        cout<< answer[i] << " " ;
    }
}