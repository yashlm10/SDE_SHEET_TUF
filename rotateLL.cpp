#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next)return head;

    ListNode* temp = head;
    int cnt = 1;
    while(temp->next){
        temp=temp->next;
        cnt++;
    }
    k = k%cnt;

    temp->next = head;//point last node to the head node

    int iter = cnt-k-1;
    ListNode* temp1 = head;
    while(iter--){
        temp1 = temp1->next;
    }
    ListNode* ans = temp1->next;
    temp1->next = NULL;
    return ans;
}

int main(){
    int value;
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* help = head;
    while(cin >> value){
        if(value==-1)break;
        ListNode* temp = new ListNode(value);
        help->next = temp;
        help = temp;
    }
    int k;
    cin >> k;

    ListNode* print = rotateRight(head,k);
    while(print){
        cout << print->data << " ";
        print = print->next;
    }
    cout << endl;
    return 0;
}