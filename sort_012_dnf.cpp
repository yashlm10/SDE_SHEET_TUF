#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &v, int n){
   int low = 0 , mid = 0 , high = n-1;
   for(int i=0;i<n;i++){
      if(v[mid]==0){
         swap(v[low],v[mid]);
         low++;
         mid++;
      }else if(v[mid] == 1){
         mid++;
      }else if(v[mid]== 2){
        swap(v[high],v[mid]);
        high--;
      }
      if(mid>high){
        break;
      }
   }
   for(int i=0;i<n;i++){
     cout << v[i] <<" ";
    }
    cout << endl;
}


int main(){
    int n;
    cin >> n;
    vector<int> v;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        v.push_back(value);
    }
    sortArray(v,n);
    return 0;
}