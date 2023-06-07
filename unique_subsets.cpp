#include <bits/stdc++.h>
using namespace std;

void helperHset(vector<int> &arr, vector<int> ds, set<vector<int>> &st, int ind, int n){
     if(ind == n){
        sort(ds.begin(),ds.end());
        st.insert(ds);
        return;
     }

     ds.push_back(arr[ind]);
     helperHset(arr,ds,st,ind+1,n);
     ds.pop_back();
     helperHset(arr,ds,st,ind+1,n);
}

void helperBacktracking(vector<int> &arr, vector<vector<int>> &answer, vector<int>&ds, int ind,int n){
    answer.push_back(ds);
    for(int i=ind;i<n;i++){
        if(i!= ind && arr[i] == arr[i-1])continue;
        ds.push_back(arr[i]);
        helperBacktracking(arr,answer,ds,i+1,n);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsHset(vector<int>&arr, int n){
    vector<vector<int>>answer;
    vector<int>ds;
    set<vector<int>> st;
    helperHset(arr,ds,st,0,n);
    for(auto it = st.begin();it != st.end();it++){
        answer.push_back(*it);
    }
    return answer;
}

vector<vector<int>> subsetsBacktracking(vector<int>&arr, int n){
    vector<vector<int>> answer;
    vector<int>ds;
    sort(arr.begin(),arr.end());
    helperBacktracking(arr,answer,ds,0,n);
    return answer;
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
    vector<vector<int>> print = subsetsBacktracking(arr,n);
    for(int i=0;i<print.size();i++){
         for(int j=0;j<print[i].size();j++){
            cout << print[i][j] << " ";
         }
         cout << endl;
    }
}