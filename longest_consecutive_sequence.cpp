#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveHashing(vector<int>& nums) {
        set<int> hashSet;
        for(int num: nums){
          hashSet.insert(num);
        }
        int lstreak = 0;
        int currStreak =0;
        for(int num: nums){
          if(!hashSet.count(num -1)){
            int currEle = num;
            currStreak =1;
            while(hashSet.count(currEle + 1)){
              currEle += 1;
              currStreak += 1;
            }
          }
          lstreak = max(lstreak, currStreak);
        } 
        return lstreak;
    }

int longestConsecutiveSort(vector<int>& nums) {
      int n= nums.size();
      if(n==0){
        return 0;
      }
      sort(nums.begin(),nums.end());
      int ans = 1;
      int cnt = 1;
      for(int i=1;i<n;i++){
        if(nums[i] == nums[i-1]+1){
           cnt++;
           ans = max(ans,cnt);
        }else if(nums[i] == nums[i-1]){
           ans = max(ans,cnt);
        }else{
           ans = max(ans,cnt);
           cnt =1;
        }
      }
      return ans;

    }

int main(){
    int n;
    cin >>n;
    vector<int> nums;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        nums.push_back(value);
    }
    int ans1 = longestConsecutiveHashing(nums);
    int ans2 = longestConsecutiveSort(nums);
    cout << ans1 << " " << ans2 << endl;
}