#include <bits/stdc++.h>
using namespace std;

 vector<int> twoSumPointer(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;
        vector<int>dup = nums;
        int i,j;
        sort(nums.begin(),nums.end());
        bool loop =1;// so that i dosent get reassigned some other value if values are same in the array, if loop = 0, it wont enter that loop
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                for(int k=0;k<dup.size();k++){
                    if(dup[k]==nums[left] && loop ){
                        i=k;
                        loop = 0;
                        continue;
                    }
                    if(dup[k]==nums[right]) j=k;
                }
               ans.push_back(i);
               ans.push_back(j);
               return ans;
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

 vector<int> twoSumHashing(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int left = target - num;
            if(hmap.find(left) != hmap.end()){
                ans.push_back(i);
                ans.push_back(hmap[left]);
                return ans;
            }
            hmap[num] = i;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        nums.push_back(value);
    }
    vector<int> ans1 = twoSumPointer(nums, target);
    vector<int> ans2 = twoSumHashing(nums, target);

    cout<< ans1[0] << " " << ans1[1] << endl;
    cout<< ans2[0] << " " << ans2[1] << endl;
}