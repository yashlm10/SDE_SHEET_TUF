#include <bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

class Solution{
    public:

    static bool comparator(meeting m1, meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        return false;
    }

    int maxMeetings(vector<int>start, vector<int>end, int n){
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i+1;
        }
        sort(meet,meet + n,comparator);
        int limit = meet[0].end;
        vector<int> answer;
        answer.push_back(meet[0].pos);

        for(int i=1;i<n;i++){
            if(meet[i].start > limit){
                limit = meet[i].start;
                answer.push_back(meet[i].pos);
            }
        }
        return answer.size();
    }

};

int main(){
    int n;
    cin >> n;
    vector<int>arr1,arr2;
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        arr1.push_back(value);
    }
    for(int i=0;i<n;i++){
        cin >> value;
        arr2.push_back(value);
    }

    Solution obj;

    int meets = obj.maxMeetings(arr1,arr2,n);

    cout << meets << endl;
    return 0;
}