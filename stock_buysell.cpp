#include <bits/stdc++.h>
using namespace std;

 int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell = prices[0], diff = 0;
        bool flag =1;
        for(int i=1;i< prices.size();i++){
           if(prices[i] - buy >= 0 ){
                if(prices[i] - buy >= diff){
                    sell = prices[i];
                    diff = sell - buy;
                }
           }else{
               if( i == (prices.size()-1) ){
                   flag =0;
               }
               buy = prices[i];
           }
        }
        if(flag){
            return diff;
        }else{
            return flag;
        }
        
    }

    int main(){
        int t;
        cin >> t;
        while(t--){
            vector<int> prices;
            int n;
            cin >> n;
           for(int i=0;i<n;i++){
               int j;
               cin >> j;
               prices.push_back(j);
           }
            int ans = maxProfit(prices);
            cout << ans << endl;
        }
    }