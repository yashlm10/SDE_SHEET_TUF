#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequentHeapMysol(int n, int k, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    vector<pair<int,int>> temp;
    int curr = arr[0];
    int idx = 0;
    pair<int,int> pair1 = {1, curr};
    temp.push_back(pair1);
    for(int i=1;i<n;i++){
        if(arr[i] == curr){
            temp[idx].first++;
        }else{
            curr = arr[i];
            idx++;
            pair<int,int>that = {1,curr};
            temp.push_back(that);
        }
    }
    vector<int> answer;
    priority_queue<pair<int,int>> ans;
    for(int i=0;i<temp.size();i++){
          ans.push(temp[i]);
    }
    while(k--){
        pair<int,int>now = ans.top();
        ans.pop();
        answer.push_back(now.second);
    }
    sort(answer.begin(),answer.end());
    return answer;
}

vector<int> KMostFrequentMapHeap(int n, int k, vector<int> &arr)
{
    if(k==n)return arr;

    map<int,int> mp;

    for(int ele : arr) mp[ele]++;

    priority_queue<pair<int,int>> max_heap;

    for(auto x:mp) max_heap.push({x.second,x.first});

    vector<int> ans(k);

    for(int i=0;i<k;i++){
        ans[i] = max_heap.top().second;
        max_heap.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}

map<int,int>mp;
vector<int> uniq;
void swapUniq(int a, int b){
    int temp = uniq[a];
    uniq[a] = uniq[b];
    uniq[b] = temp;
}
int partition(int left, int right, int pivot){
    int pFreq = mp[uniq[pivot]];
    
    swapUniq(pivot,right);
    int idx = left;

    for(int i=left;i<=right;i++){
        if(mp[uniq[i]] < pFreq){
            swapUniq(idx,i);
            idx++;
        }
    }
    swapUniq(idx,right);
    return idx;
}
void quickSelect(int left,int right, int kSmall){
    if(left == right)return;
    
    int pivot = left + rand()%(right-left);

    pivot = partition(left, right, pivot);

    if(kSmall == pivot)return;
    else if(kSmall < pivot) quickSelect(left, pivot-1, kSmall);
    else quickSelect(pivot+1, right, kSmall);
}
vector<int> KMostFrequentQuickSelect(int n, int k, vector<int> &arr)
{
    mp.clear();
    
    for(int ele:arr)mp[ele]++;
    
    int size = mp.size();
    uniq.assign(size,0);
    int i=0;
    
    for(auto x:mp)uniq[i++] = x.first;
    
    quickSelect(0,size-1,size-k);
    
    vector<int>top;
    for(int i=size-k;i<size;i++){top.push_back(uniq[i]);}

    sort(top.begin(),top.end());
    return top;
    
}

vector<int> KMostFrequentBucket(int n, int k, vector<int> &arr)
{
    map<int,int> mp;
    for(int ele : arr) mp[ele]++;
    
    vector<int>bucket[n+1];
    for(auto x:mp){
        int freq = x.second;
        bucket[freq].push_back(x.first);
    }
    
    vector<int>ans(k);
    int cur =0;

    for(int i=n;i>0 && k>0;i--){
        if(bucket[i].size() == 0){
            continue;
        }
        for(int num:bucket[i]){
            ans[cur++] = num;
            k--;
            if(k==0){
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    int value;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin >> value;
        arr.push_back(value);
    }
    vector<int> jawab = KMostFrequentBucket(n,k,arr);
    for(int i=0;i<k;i++){
        cout << jawab[i] << " ";
    }
    return 0;
}