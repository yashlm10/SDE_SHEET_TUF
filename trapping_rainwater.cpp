#include <bits/stdc++.h>
using namespace std;

int trapbrute(vector<int>& height) {
        int n = height.size();
        int trap = 0;
        for(int i=0;i<n;i++){
            int leftmax =0,rightmax=0;
           int j = i;
           while(j>=0){
               leftmax = max(leftmax,height[j]);
               j--;
           }
            j=i;
           while(j<n){
               rightmax = max( rightmax,height[j]);
               j++;
           }
           
           trap +=  min(leftmax,rightmax) - height[i];
        }
        return trap;
    }

int trappremax(vector<int>& height) {
        int n = height.size();
        int prefix[n],suffix[n];
        prefix[0]= height[0];
        for(int i=1;i<n;i++){
            prefix[i] = max(prefix[i-1],height[i]);
        }
        suffix[n-1]= height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1],height[i]);
        }
        int trap =0;
        for(int i =1;i<n-1;i++){
            trap += min(prefix[i],suffix[i]) - height[i];
        }
        return trap;
}

int traptwoptr(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int leftmax=0,rightmax=0;
        int trap=0;
        while(l<=r){
            if(height[l]<height[r]){
               if(height[l]>leftmax){
                   leftmax = height[l];
               }else{
                   trap += leftmax - height[l];
               }
               l++;
            }else{
                if(height[r]>rightmax){
                    rightmax = height[r];
                }else{
                    trap += rightmax-height[r];
                }
                r--;
            }
        }
        return trap;
}

int main(){
    int n;
    cin >> n;
    vector<int> height;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        height.push_back(value);
    }
    int ans1 =  trapbrute(height);
    int ans2 =  trappremax(height);
    int ans3 =  traptwoptr(height);

    cout << ans1 << " " << ans2 << " " << ans3;
    return 0;
}