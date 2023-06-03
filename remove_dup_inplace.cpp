#include <bits/stdc++.h>
using namespace std;

int removeDuplicatesHashSet(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i=0;i<n;i++){
           st.insert(nums[i]);
        }
        int k = st.size();
        int j=0;
        for(auto x : st){
            nums[j++] = x;
        }
        return k;
}

int removeDuplicatesTwoptr(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=i+1;
        while(j<n){
            if(nums[i]==nums[j])j++;
            else nums[++i] = nums[j];
        }
        return i+1;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        nums.push_back(value);
    }
    int ans = removeDuplicatesTwoptr(nums);
    for(int i = 0;i<ans;i++){
        cout << nums[i] << " ";
    }
    
}