#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
         int n = nums.size();
         int lo = 0;
         int hi = n-1;
         while(lo <= hi){
             int mid = (hi+lo)/2;
             if(nums[mid]==target) return mid;
             if(nums[lo] <= nums[mid]){
                 if(nums[lo] <= target && nums[mid] >= target){
                     hi = mid;
                 }else{
                     lo = mid+1;
                 }
             }else{
                 if(nums[mid] <= target && nums[hi] >= target){
                     lo = mid;
                 }else{
                     hi = mid -1;
                 }
             }
         }
         return -1;
}

int main(){
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int>nums;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        nums.push_back(value);
    }

    int answer = search(nums,target);
    cout << answer << endl;
 }