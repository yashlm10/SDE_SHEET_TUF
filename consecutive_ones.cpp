#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi =0,temp=0;
        for(int i=0;i<n;i++){
            if(nums[i]) temp++;
            else temp = 0;

            maxi = max(maxi,temp);
        }
        return maxi;
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
    int ans1 = findMaxConsecutiveOnes(nums);
    cout << ans1;
    return 0;
}