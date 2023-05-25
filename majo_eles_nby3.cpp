#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement_boyerMooreAlgo(vector<int>& nums) {

        int n = nums.size();
        int cnt1=0,cnt2=0;
        int ele1 = INT_MIN,ele2= INT_MIN;

        for(int i=0;i<n;i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1++;
            }else if(cnt2 ==0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2++;
            }else if(nums[i]==ele1){
                cnt1++;
            }else if(nums[i]==ele2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> answer;
        int count1 =0, count2=0;
        for(int i=0;i<n;i++){
            if(nums[i] ==ele1)count1++;
            if(nums[i] ==ele2)count2++;
        }
        if(count1>(n/3))answer.push_back(ele1);
        if(count2>(n/3))answer.push_back(ele2);
        return answer;
}

vector<int> majorityElement_hashmap(vector<int>& nums) {
        int n = nums.size();
        map<int,int> hmap;
        for(int i=0;i<n;i++){
            hmap[nums[i]]++;
        }
        vector<int> answer;
        for(auto it: hmap){
            if(it.second > n/3){
                answer.push_back(it.first);
            }
        }
        return answer;
}

int main(){
    int n;
    cin >>n;
    int value;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin >> value;
        v.push_back(value);
    }
    vector<int> v1 = majorityElement_boyerMooreAlgo(v);
    vector<int> v2 = majorityElement_hashmap(v);
    for(int i=0;i<v1.size();i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<v2.size();i++){
        cout << v2[i] << " ";
    }



}