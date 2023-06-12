#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicateIterative(vector<int>& nums) {
        int lo = 0;
        int hi = 1;
        while(hi < nums.size()-1){
            if(nums[lo] != nums[hi])return nums[lo];
            lo += 2;
            hi += 2;
        }
        return nums[nums.size()-1];
}

int singleNonDuplicateBinary(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(mid%2){
                if(nums[mid] == nums[mid+1]) hi = mid-1;
                else if(nums[mid] == nums[mid-1]) lo = mid+1;
                else return nums[mid];
            }
            else{
                if(nums[mid] == nums[mid+1]) lo = mid;
                else if(nums[mid] == nums[mid-1]) hi = mid;
                else return nums[mid];
            }
        }
        return nums[lo];
}

 int main(){
    int n;
    cin >> n;
    vector<int>nums;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        nums.push_back(value);
    }

    int answer = singleNonDuplicateBinary(nums);
    cout << answer << endl;
 }