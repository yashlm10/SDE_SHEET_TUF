#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumHashing(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;i<n-2;j++){
                set<long long> hset;
                for(int k= j+1;k<n;k++){
                    long long num = nums[i] + nums[j];
                    num += nums[k];
                    long long fourth = target - num;
                    if(hset.find(fourth) != hset.end()){
                        vector<int>temp = {nums[i], nums[j], nums[k], (int)(fourth) };
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }

vector<vector<int>> fourSumTwoPtr(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int i =0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
               if(j> i+1 && nums[j] == nums[j-1]) continue;
               int left = j+1;
               int right = n-1;
                while(left<right){
                   long long sum = nums[i];
                   sum += nums[j];
                   sum += nums[left];
                   sum += nums[right];
                    
                    if(sum == target){
                       vector<int> temp = {nums[i],nums[j],nums[left],nums[right]};
                       answer.push_back(temp);
                      int temp1 = left;
                      int temp2 = right;
                      while(left<right && nums[left] == nums[temp1]) left++;
                      while(left<right && nums[right] == nums[temp2]) right--;
                    }else if(sum < target){
                       left++;
                    }else{
                       right--;
                    }
                    
                }
             
               
            }
        }
        return answer;
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
    vector<vector<int>> ans1 = fourSumTwoPtr(nums, target);
   // vector<vector<int>> ans2 = fourSumHashing(nums, target);

    for(int i=0;i<ans1.size();i++){
        cout << ans1[i][0] << " " << ans1[i][1]<< " " << ans1[i][2] << " " << ans1[i][3] << endl;
    }
    /*for(int i=0;i<ans1.size();i++){
        cout << ans2[i][0] << " " << ans2[i][1] << ans2[i][2] << " " << ans2[i][3] << endl;
    }*/
}