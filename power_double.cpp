#include <bits/stdc++.h>
using namespace std;

 double myPow(double x, int n) {
      long long nn = n;
      if(nn<0) nn *= (-1);
      double ans = 1.0;
      while(nn){
        if(nn % 2){
            ans *= x;
            nn--;
        }else{
            x *= x;
            nn /= 2;
        }
      }
      if(n<0) ans = (double)(1.0)/(double)(ans);
      return ans;
}

int main() {
    double x;
    cin >> x;
    int n;
    cin >> n;
    double answer = myPow(x,n);
    cout << answer << endl;
}