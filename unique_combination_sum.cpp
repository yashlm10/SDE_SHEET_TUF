#include <bits/stdc++.h>
using namespace std;

void helpermysol(int ind, int target, vector<int> &ds, vector< vector<int>> &answer, vector<int> &candidates){
        
        if(target==0){
            answer.push_back(ds);
            
            return;
        }//else if(target<0)return;
        
        for(int i=ind;i<candidates.size();i++){
            if(i!=ind && candidates[i]==candidates[i-1])continue;
            if(target<0)break;
            ds.push_back(candidates[i]);
            helpermysol(i+1,target-candidates[i],ds,answer,   candidates);
            ds.pop_back();
        }
}
    
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        helpermysol(0,target,ds,answer,candidates);
        return answer;
    }

int main(){
    vector<int> candidates;
    int n;
    cin>>n;
    int target;
    cin >> target;
    for(int i=0;i<n;i++){
        int j;
        cin >> j;
        candidates.push_back(j);
    }
    vector<vector<int>> print = combinationSum(candidates,target);
    for(int i=0;i<print.size();i++){
         for(int j=0;j<print[i].size();j++){
            cout << print[i][j] << " ";
         }
         cout << endl;
    }
}