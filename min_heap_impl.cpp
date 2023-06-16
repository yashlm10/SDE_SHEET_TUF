#include <bits/stdc++.h>
using namespace std;

vector<int> minHeapPQ(int n, vector<vector<int>>& q) {
    priority_queue<int, vector<int>, greater<int>>min_heap;
    vector<int>answer;
    for(int i=0;i<q.size();i++){
        if(q[i][0]){
            if(min_heap.empty()) answer.push_back(INT_MIN);
            answer.push_back(min_heap.top());
            min_heap.pop();
        }else{
            min_heap.push(q[i][1]);
        }
    }
    return answer;
}
 
int left(int i){return (2*i +1);}

int right(int i) {return (2*i +2);}

int parent(int i) {return ((i-1)/2);}

void minHeapify(vector<int>&heap, int &size, int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    
    if(l<size && heap[l] < heap[i]){
      smallest = l;
    }
    if(r<size && heap[r] < heap[smallest]){
        smallest = r;
    }
    
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        minHeapify(heap,size,smallest);
    }
}

void insert(vector<int>&heap, int &size, int val){
    heap[size] =val;
    int i=size;
    size++;
    
    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

int extractMin(vector<int>&heap, int &size){
    if(size == 1){
        size--;
        int ans = heap[0];
        
        return ans;
    }

    int ans = heap[0];
    heap[0] = heap[size-1];
    size--;
    
    minHeapify(heap,size,0);
    
    return ans;
}

vector<int> minHeapArrayImplementation(int n, vector<vector<int>>& q) {
    int size =0;
    vector<int> heap(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(q[i][0]){
            int answer = extractMin(heap, size);
            ans.push_back(answer);
        }else{
            insert(heap, size, q[i][1]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> q;
    for(int i=0;i<n;i++){
        vector<int> temp;
        int t;
        cin >>t;
        temp.push_back(t);
        int b;
        if(!t){
            cin >> b;
            temp.push_back(b);
        }
        q.push_back(temp);
    }
    vector<int> answer = minHeapArrayImplementation(n,q);
    for(int i=0;i< answer.size();i++){
        cout << answer[i] <<endl;
    }
}