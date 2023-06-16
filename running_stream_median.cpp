#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    vector<int> temp;
    vector<int> ans;
    for(int i=0;i<n;i++){
        temp.push_back(arr[i]);
        int m = i+1;
        sort(temp.begin(),temp.end());
        if(m%2){
           ans.push_back(temp[m/2]);
        }else{
           int mid = (temp[m/2] + temp[(m/2)-1])/2;
           ans.push_back(mid);
        }
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
}

void findMedianHeap(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> maxx_heap;
    int median;
    for(int size = 1;size <= n;size++){
        if(!maxx_heap.empty() && maxx_heap.top() > arr[size-1]){
            maxx_heap.push(arr[size-1]);
            if(maxx_heap.size() > min_heap.size()+1){
                min_heap.push(maxx_heap.top());
                maxx_heap.pop();
            }
        }else{
            min_heap.push(arr[size-1]);
            if(min_heap.size() > maxx_heap.size()+1){
                maxx_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        if(size%2){
            if(min_heap.size() > maxx_heap.size()){
                median = min_heap.top();
            }else{
                median = maxx_heap.top();
            }
        }else{
            median = (min_heap.top() + maxx_heap.top())/2;
        }
        cout << median << " ";
    }  
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    int value;
    for(int i=0;i<n;i++){
        cin >> value;
        arr[i] = value;
    }
    findMedianHeap(arr, n);
    return 0;
}