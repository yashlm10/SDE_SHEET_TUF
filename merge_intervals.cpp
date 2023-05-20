#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i< intervals.size();i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;
    }

int main(){
    int n;cin >> n;
    vector<vector<int>> intervals;
    int value;
    for(int i=0;i<n;i++){
        vector<int> interval;
        cin >> value;
        interval.push_back(value);
        cin >> value;
        interval.push_back(value);
        intervals.push_back(interval);
    }

    vector<vector<int>> answer = merge(intervals);
    for(int i=0;i< answer.size();i++){
        cout<<answer[i][0] << " " << answer[i][1]<< endl;
    }
    return 0;
}