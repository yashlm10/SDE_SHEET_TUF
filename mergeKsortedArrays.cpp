#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArraysBrute(vector<vector<int>>&kArrays, int k)
{
    vector<int> master;
    for(int i=0;i<k;i++){
        for(int j=0;j<kArrays[i].size();j++){
            master.push_back(kArrays[i][j]);
        }
    } 
    sort(master.begin(),master.end());
    return master;
}

vector<int> merge(vector<int>&a, vector<int>&b){
    int n = a.size(), m = b.size();
    int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(a[i] < b[j]){
           ans.push_back(a[i]);
           i++;
        }else{
           ans.push_back(b[j]);
           j++;
        }
    }
    while(i<n){
        ans.push_back(a[i]);
        i++;
    }
    while(j<m){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
vector<int> mergeHelper(vector<vector<int>>&kArrays, int start, int end){
    if(start == end){
        return kArrays[start];
    }
    if(start+1 == end){
        merge(kArrays[start],kArrays[end]);
    }

    int mid = start + (end-start)/2;
    vector<int>first = mergeHelper(kArrays,start,mid);
    vector<int>second = mergeHelper(kArrays,mid+1,end);
        
    return merge(first,second);

}
vector<int> mergeKSortedArraysDivideNconquer(vector<vector<int>>&kArrays, int k)
{
    vector<int>ans = mergeHelper(kArrays,0,k-1);
    return ans;
    
}

vector<int> mergeKSortedArraysHeap(vector<vector<int>>&kArrays, int k)
{
    vector<int> result;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>min_heap;
    
    for(int i=0;i<kArrays.size();i++){
        min_heap.push({kArrays[i][0],{i,0}});
    }
    
    while(!min_heap.empty()){
        pair<int,pair<int,int>>curr = min_heap.top();
        min_heap.pop();
        
        int i = curr.second.first;
        int j = curr.second.second;
        
        result.push_back(curr.first);
        
        if(j+1 < kArrays[i].size()){
            min_heap.push({kArrays[i][j+1],{i,j+1}});
        }
    }
    return result;
}

int main(){
    int k;
    cin >> k;
    vector<vector<int>> kArrays;
    for(int i=0;i<k;i++){
        vector<int>temp;
        int n;
        cin >> n;
        int value;
        for(int i=0;i<n;i++){
           cin >> value;
           temp.push_back(value);
        }
        kArrays.push_back(temp);
    }

    vector<int> jawab = mergeKSortedArraysHeap(kArrays, k);

    for(int i=0;i< jawab.size();i++){
        cout << jawab[i] << " ";
    }
    return 0;
}