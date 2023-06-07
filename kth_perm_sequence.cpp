#include <bits/stdc++.h>
using namespace std;

void helper(string &str,vector<string> &answer,int ind,int n){
        if(ind == n){
            answer.push_back(str);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(str[i],str[ind]);
            helper(str,answer,ind+1,n);
            swap(str[i],str[ind]);
        }
}

string getPermutationRecurr(int n, int k) {
        string str;
        for(int i=1;i<=n;i++){
            str.push_back(i + '0');
        }
        vector<string> answer;
        helper(str,answer,0,n);
        sort(answer.begin(), answer.end());
        auto it = answer.begin() + (k-1);
        return *it;
}

string getPermutationOptimal(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k--;
        string ans = "";
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            if(!nums.size())break;

            k %= fact;
            fact /= nums.size();
        }
        return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    string a = getPermutationRecurr(n,k);
    cout << a << endl;
    return 0;
}