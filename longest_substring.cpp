#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringOptimal(string s) {
       
        vector<int> mpp(256, -1);
        int l = 0;
        int r = 0;
        int len = 0;
        
        while(r < s.size()){
            if(mpp[s[r]] != -1)
                l = max(l, mpp[s[r]]+1);
                
                mpp[s[r]] = r;
                len = max(len, r-l+1);
                r++;
            
           
        }
        return len;
    }

int lengthOfLongestSubstringHash(string s) {
        if(s.size()==0){
            return 0;
        }
        if(s == " "){
            return 1;
        }
        int left = 0;
        
        int len = INT_MIN;
        unordered_set<int> hset;
        for(int right = 0;right< s.length();right++){
           if(hset.find(s[right]) != hset.end()){
                while(left<right && hset.find(s[right]) != hset.end()){
                    hset.erase(s[left]);
                    left++;

                }
           }
           len = max(len, right - left+1);
           hset.insert(s[right]);
        }
        return len;
    }

int lengthOfLongestSubstringLoop(string s) {
        
        if(s == " "){
            return 1;
        }
        if(s.size() == 0){
            return 0;
        }
        int len = INT_MIN;
        
        for(int i=0;i<s.length();i++){
            unordered_set<int> hset;
            for(int j=i;j<s.length();j++){
               if(hset.find(s[j]) != hset.end()){
                   len = max(len, j-i);
                   break;
               }
               if(j==s.length() - 1) len = max(len, j-i+1);
               hset.insert(s[j]);
            }
        }
        if(len == INT_MIN)len = s.length();
        return len;
    }

int main(){
    string s;
    cin >> s;
    int ans1 = lengthOfLongestSubstringOptimal(s);
    int ans2 = lengthOfLongestSubstringHash(s);
    int ans3 = lengthOfLongestSubstringLoop(s);

    cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}