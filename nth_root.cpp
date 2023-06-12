#include <bits/stdc++.h>
using namespace std; 

double power(int n,double mid){
    double z= 1.0;
    for(int i=0;i<n;i++){
        z *= mid;
    }
    return z;
}

double findroot(int n,int m){
    double lo = 1.0;
    double hi = (double)m;
    double eps = 1e-6;
    while((hi-lo) > eps){
       double mid = (hi+lo)/2.0;
       double temp = power(n,mid);
       if(temp > (double)m) hi = mid;
       else lo = mid;
    }
    return lo;
}

int main(){
    int n,m;
    cin >> n >> m;
    double answer = findroot(n,m);
    cout << answer << endl;
}