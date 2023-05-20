#include <bits/stdc++.h>
using namespace std;

int find_duplicate_hashing(vector<int> arr1, int n){
    int ans;
    vector<int> freq(n+1,0);
    for(int i=0;i<=n;i++){
        if(freq[arr1[i]]==1){
            ans = arr1[i];
            break;
        }else{
            freq[arr1[i]]++;
        }
    }
    return ans;
}

int find_duplicate_haretort(vector<int> arr2, int n){
    
    int slow = arr2[0];
    int fast = arr2[0];
    do{
       slow = arr2[slow]; // moivng one step to the next element pointed to
       fast = arr2[arr2[fast]]; //moving two steps, to the element pointed by the primarily pointed element
    }while( slow != fast);
 
    fast = arr2[0];
    while(slow != fast){
        slow = arr2[slow];// moivng one step to the next element pointed to
        fast = arr2[fast];// moivng one step to the next element pointed to
    }
    return slow;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr;
    int value;
    for(int i=0;i<=n;i++){
       cin >> value;
       arr.push_back(value);
    }
    int ans1 = find_duplicate_hashing(arr,n);
    int ans2 = find_duplicate_haretort(arr,n);

    cout << ans1 << " " << ans2 << endl;

    return 0;
}