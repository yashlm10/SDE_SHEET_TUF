#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode* bottom;
    ListNode(): data(0),next(nullptr),bottom(nullptr) {}
    ListNode(int x): data(x), next(nullptr),bottom(nullptr) {}
    ListNode(int x,ListNode* bottom): data(x),next(nullptr),bottom(bottom) {}
    ListNode(int x,ListNode* next, ListNode* bottom): data(x),next(next),bottom(bottom) {}
};

ListNode* mergeLists(ListNode* a,ListNode* b){
    ListNode* temp = new ListNode();
    ListNode* res = temp;
    while(a && b){
        if(a->data < b->data){
            temp->bottom = a;
            a =a->bottom;
            temp = temp->bottom;
        }else{
            temp->bottom = b;
            b =b->bottom;
            temp = temp->bottom;
        }
    }
    if(a) temp->bottom = a;
    else temp->bottom = b;

    return res->bottom;
}

ListNode* flattenLL(ListNode* head){
    if(!head || !head->next) return head;

    head->next = flattenLL(head->next);

    head = mergeLists(head,head->next);

    return head;
}

int main(){
    vector<int>v;
    int n;
    cin >> n;
    int m=n;
    int value;
    for(int i=0;i<n;i++){
      cin >> value;
      value--;
      v.push_back(value);
    }
    int root;
    cin >> root;
    ListNode* head = new ListNode(root);
    n--;
    ListNode* tempb = head;
    ListNode* tempn = head;
    int val;
    while(n--){
       cin >> val;
       ListNode* nxt = new ListNode(val);
       tempn->next = nxt;
       tempn = nxt;
    }
    tempn = head;
    for(int i=0;i<m;i++){
        while(v[i]--){
            cin >> val;
            ListNode* bot = new ListNode(val);
            tempb->bottom = bot;
            tempb = bot;
        }
        tempb = tempn->next;
        tempn = tempn->next;
    }
    ListNode* print = flattenLL(head);
    while(print){
        cout << print->data << " ";
        print = print->bottom;
    }
    return 0;
}
