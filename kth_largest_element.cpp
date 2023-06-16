#include <bits/stdc++.h>
using namespace std;

int partition(int left, int right, vector<int>&nums, int k){
        int pivot = nums[left];
        int l = left+1, r = right;
        while(l <= r){
            if(pivot > nums[l] && pivot < nums[r]){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            if(pivot <= nums[l]) l++;
            if(pivot >= nums[r]) r--;
        }
        swap(nums[left], nums[r]);
        return r;
}

int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n-1,kth;
        while(1){
            int idx = partition(left, right, nums, k);
            if(idx == k-1){
                kth = nums[idx];
                break;
            }
            if(idx < k-1){
                left = idx+1;
            }else{
                right = idx -1;
            }
        }
        return kth;
}

int findKthLargestPQ(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        int x = k-1;
        while(x--){
            q.pop();
        }
        return q.top();
}

int findKthSmallestPQ(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        int x = k-1;
        while(x--){
            q.pop();
        }
        return q.top();
}

int partitionSmallest(int left, int right, vector<int> &nums, int k){
    int pivot = nums[left];
    int l = left + 1, r = right;
    while(l <= r){
      if(pivot > nums[r] && pivot < nums[l]){
          swap(nums[l], nums[r]);
          l++;
          r--;
      }
      if(nums[l] <= pivot){
          l++;
      }
      if(nums[r] >= pivot){
          r--;
      }
    }
    swap(nums[left],nums[r]);
    return r;
}

int findKthSmallest(vector<int>&nums, int k){
    int left = 0, right = nums.size() -1;
    while(1){
        int idx = partitionSmallest(left, right, nums,k);
        if(idx == k-1){
             return nums[idx];
        }
        if(idx < k-1){
            left = idx + 1;
        }else{
            right = idx - 1;
        }
    }
    return INT_MAX;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int value;
    int k;
    cin >> k;
    for(int i=0;i<n;i++){
        cin >> value;
        nums.push_back(value);
    }
    int answer = findKthSmallest(nums, k);
    cout << answer << endl;
    return 0;
}