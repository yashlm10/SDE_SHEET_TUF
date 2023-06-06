#include <bits/stdc++.h>
using namespace std;

int findPlatformOptimal(vector<int> arr, vector<int> dep, int n)
    {
    	sort(arr.begin(),arr.end());
    	sort(dep.begin(), dep.end());
    	int ans = 0,count= 0;
    	int i=0,j=0;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        i++;
    	        count++;
    	    }else{
    	        j++;
    	        count--;
    	    }
    	    ans = max(ans,count);
    	}
    	return ans;
}

int findPlatform(vector<int> arr, vector<int> dep, int n)
    {
    	int ans = 1;
    	for(int i=0;i<n;i++){
    	    int cnt =1;
    	    for(int j = i+1;j<n;j++){
    	        if(arr[i]<=arr[j] && arr[j]<=dep[i] || arr[i]>=arr[j] && dep[j]>=arr[i]){
    	            cnt++;
    	        }
    	    }
    	    ans = max(ans,cnt);
    	}
    	return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr1,arr2;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        arr1.push_back(value);
    }
    for(int i=0;i<n;i++){
        cin >> value;
        arr2.push_back(value);
    }
    
    int ans = findPlatformOptimal(arr1,arr2,n);
    cout << ans;

    return 0;
}