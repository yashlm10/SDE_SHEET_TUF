#include <bits/stdc++.h>
using namespace std;

 void print_duplicate_missing_math(vector<int> arr, int n){
      int dup,mis;
      int sumOriginal = n*(n+1)/2;
      int sumSqOriginal = n*(n+1)*(2*n + 1)/6;
      int sumNew=0, sumSqNew =0;
      for(int i=0;i<n;i++){
        sumNew += arr[i];
        sumSqNew += arr[i]*arr[i];
      }
      dup = (((sumSqNew-sumSqOriginal)/(sumNew-sumOriginal)) + (sumNew-sumOriginal))/2;
      mis = dup - (sumNew-sumOriginal);
      cout << dup << " " << mis << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr;
    int value;
    for(int i=0;i<n;i++){
       cin >> value;
       arr.push_back(value);
    }
    print_duplicate_missing_math(arr,n);

    return 0;
}