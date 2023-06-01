#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

ListNode* reverseListSL(ListNode* head){
    ListNode* dummy = NULL;
    while(head){
        ListNode* next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
}

ListNode* reverseListDL(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* nxt;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

ListNode* reverseListRecurr(ListNode* head){

    if(head==NULL|| head->next == NULL){
        return head;
    }
    ListNode* rnode = reverseListRecurr(head->next);
    head->next->next = head;
    head->next = NULL;
    return rnode;
}

int main() {
    int value;
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* help = head;
    while(cin >> value){
        ListNode* temp = new ListNode(value);
        help->next = temp;
        help = temp;
    }


    ListNode* print = reverseListRecurr(head);
    while(print){
        cout << print->data << " ";
        print = print->next;
    }
    cout << endl;
 
}