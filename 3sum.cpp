#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>answer;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<n-2;i++){

            if(i==0 || nums[i]!=nums[i-1]){

                int lo = i+1,hi = n-1,sum = 0 - nums[i];

                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){

                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        answer.push_back(temp);

                        while(lo<hi && nums[lo]==nums[lo+1])lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])hi--;

                        lo++;hi--;

                    }
                    else if(nums[lo]+nums[hi]<sum) lo++;
                    else hi--;
                }
            }
        }
        return answer;
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
    vector<vector<int>> ans1 = threeSum(nums);
   
    for(int i=0;i<ans1.size();i++){
        cout << ans1[i][0] << " " << ans1[i][1]<< " " << ans1[i][2] << endl;
    }
    
}