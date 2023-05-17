#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermSTL(vector<int> &v){
    next_permutation(v.begin(),v.end());
    return v;
}

vector<int> nextPermOptimal(vector<int> &v){
    int breakpoint = -1;
    for(int i = (v.size()-2);i>=0;i--){
        if(v[i] < v[i+1]){
           breakpoint = i;
           break;
        }

    }
   

    if(breakpoint == -1){
        reverse(v.begin(),v.end());
        return v;
    }
    
    for(int i = v.size()-1;i>breakpoint;i--){
        if(v[i]>v[breakpoint]){
            swap(v[breakpoint],v[i]);
            break;
        }
    }
    
    reverse(v.begin() + breakpoint + 1,v.end());
    return v;

   
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        int value;
        for(int i=0;i<n;i++){
          cin >> value;
          v.push_back(value);
        }
       
        vector<int>temp = v;
        vector<int> u;
        u = nextPermSTL(v);
        vector<int> w;
        w = nextPermOptimal(temp);
        for(int i=0;i<n;i++){
          cout << u[i] << " ";
        }
        cout << endl;
        for(int i=0;i<n;i++){
          cout << w[i] << " ";
        }
        cout << endl;

    }
    return 0;
}