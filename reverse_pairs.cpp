#include <bits/stdc++.h>
using namespace std;

    int merge(vector<int> &nums, int low, int mid, int high){
       int total = 0;
       int j= mid+1;
       for(int i=low;i<= mid;i++){
           while(j<=high && nums[i] > (2*(long long)nums[j])){
               j++;
           }
           total += j-(mid+1);
        }
       vector<int> temp;
       int left = low, right = mid+1;

       while(left <= mid && right <= high){
           if(nums[left]<= nums[right]){
               temp.push_back(nums[left++]);
               
           }else{
               temp.push_back(nums[right++]);
            
           }
       }
       while(left <= mid){
           temp.push_back(nums[left++]);
           
       }
       while(right <= high){
           temp.push_back(nums[right++]);
           
       }
       int z=0;
       for (int i = low; i <= high; i++) {
           nums[i] = temp[z++];
        }
       return total;
    }
       
    
    int mergeSort(vector<int> &nums, int low, int high){
        int inv = 0;
        if(low>=high) return 0;
        int mid = (low+high)/2;
        inv = mergeSort(nums,low,mid);
        inv += mergeSort(nums, mid+1,high);
        inv += merge(nums,low,mid,high);
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        int answer = mergeSort(nums, 0 , nums.size()-1);
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
			int answer = reversePairs(nums);
			cout << answer << endl;
}