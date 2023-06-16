#include <bits/stdc++.h>
using namespace std;

vector<int> kMaxSumCombinationHeap(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	priority_queue<pair<int,pair<int,int>>>max_heap;
	set<pair<int,int>> st;
	max_heap.push({a[n-1] + b[n-1], {n-1,n-1}});
	st.insert({n-1,n-1});
	vector<int> answer;
	
	while(k>0){
		pair<int,pair<int,int>>top = max_heap.top();
		max_heap.pop();
		 int sum = top.first;
		 int x = top.second.first;
		 int y = top.second.second;
		 
		answer.push_back(sum);

		if(st.find({x-1,y}) == st.end()){
			max_heap.push({a[x-1]+ b[y], {x-1,y}});
			st.insert({x-1,y});
		}
		if(st.find({x,y-1}) == st.end()){
			max_heap.push({a[x]+ b[y-1], {x,y-1}});
			st.insert({x,y-1});
		}
		
		k--;
	}
	return answer;
	
}

vector<int> kMaxSumCombinationBrute(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> answer;
	for(int i=0;i<n;i++){
		for(int j = 0; j<n ;j++){
			answer.push_back(a[i] + b[j]);
		}
	}
	sort(answer.begin(),answer.end());
	int z = (n*n)-1;
	vector<int> ans;
	while(k--){
		ans.push_back(answer[z]);
		z--;
	}
	return ans;
	
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    int value;
    int k;
    cin >> k;
    for(int i=0;i<n;i++){
        cin >> value;
        a.push_back(value);
    }
    for(int i=0;i<n;i++){
        cin >> value;
        b.push_back(value);
    }
    vector<int> result = kMaxSumCombinationHeap(a,b,n,k);
    for(int i=0;i< result.size();i++){
        cout << result[i] <<" ";
    }
    return 0;
}