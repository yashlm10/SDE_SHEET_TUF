#include <bits/stdc++.h>
using namespace std;

bool boolIsPrime(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--])return false;
        }
        return true;
}
    
void helper(vector<vector<string>>&answer, vector<string>&ds,string s,int ind){
        if(ind == s.size()){
            answer.push_back(ds);
            return;
        }
       for(int i = ind;i<s.size();i++){
           if(boolIsPrime(s,ind,i)){
               ds.push_back(s.substr(ind,i-ind+1));
               helper(answer,ds,s,i+1);
               ds.pop_back();
           }
       }
}
    
vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> ds;
        helper(answer,ds,s,0);
        return answer;
}

int main(){
    string s;
    cin>>s;
    vector<vector<string>> stringans = partition(s);
    for(int i=0;i<stringans.size();i++){
         for(int j=0;j<stringans[i].size();j++){
            cout << stringans[i][j] << " ";
         }
         cout << endl;
    }
    return 0;
}