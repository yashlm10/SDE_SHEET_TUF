#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>&nums, vector<vector<int>> &answer,int ind){
     if(ind == nums.size()){
         answer.push_back(nums);
         return;
     }
     for(int i=ind;i<nums.size();i++){
         swap(nums[i],nums[ind]);
         helper(nums,answer,ind+1);
         swap(nums[i],nums[ind]);
     }
}
    
vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> answer;
      helper(nums,answer,0);
      return answer;
}

int main(){
    vector<int>nums;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        nums.push_back(value);
    }
    vector<vector<int>> ans = permute(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}
 