#include <bits/stdc++.h>
using namespace std;

void merge_optimal(vector<int>&arr1, vector<int>&arr2, int n, int m){
    int l = min(n,m), left = n-1, right = 0;
    for(int i=0;i<l;i++){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
  

}

void merge_shellsort_gap(vector<int>&temp1, vector<int>&temp2, int n, int m){
    int len = n+m;
    int gap = (len/2) + (len%2);
    
    
    while(gap > 0){
       int left =0; 
       int right = left + gap;


       while(right < len){
         
        if(left < n && right >= n){
            if(temp1[left]>temp2[right-n])
             swap(temp1[left],temp2[right-n]);
            
        }
        else if(left >= n){
            if(temp2[left-n]>temp2[right-n])
             swap(temp2[left-n],temp2[right-n]);
            
        }else{
            if(temp1[left]>temp1[right])
             swap(temp1[left],temp1[right]);
        }
        left++;
        right++;
       }

        if(gap == 1)
            break;
        
        gap = (gap/2) + (gap%2);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>arr1,arr2;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        arr1.push_back(value);
    }
    for(int i=0;i<m;i++){
        cin >> value;
        arr2.push_back(value);
    }

    vector<int> temp1, temp2;
    temp1 = arr1;
    temp2 = arr2;
   
    merge_optimal(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
       cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<m;i++){
       cout << arr2[i] << " ";
    }
    cout << endl;

   
   merge_shellsort_gap(temp1,temp2,n,m);
    for(int i=0;i<n;i++){
       cout << temp1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<m;i++){
       cout << temp2[i] << " ";
    }
    return 0;
}