#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode* random;
    ListNode(): data(0),next(nullptr),random(nullptr) {}
    ListNode(int x): data(x), next(nullptr),random(nullptr) {}
    ListNode(int x,ListNode* bottom): data(x),next(nullptr),random(bottom) {}
    ListNode(int x,ListNode* next, ListNode* bottom): data(x),next(next),random(bottom) {}
};

ListNode* copyRandomListHash(ListNode* head) {
        if(!head)return NULL;
        unordered_map<ListNode*,ListNode*>mpp;
        ListNode* temp = head;
        ListNode* newhead = new ListNode(temp->data);
        ListNode* newtemp = newhead;
        mpp[temp] = newtemp;
        temp=temp->next;

        while(temp){
            ListNode* clone = new ListNode(temp->data);
            newtemp->next = clone;
            newtemp = clone;
            mpp[temp] = newtemp;
            temp = temp->next;
        }
        newtemp = newhead;
        temp = head;
        
        while(temp){
            newtemp->random = mpp[temp->random];
            newtemp = newtemp->next;
            temp = temp->next;
        }
        return newhead;
        
}

ListNode* copyRandomListOptimal(ListNode* head) {
        if(!head)return NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* newnode = new ListNode(temp->data);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            if(temp->random)temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        ListNode* dummy = new ListNode(0);
        temp = dummy;
        ListNode* itr = head;
        ListNode* fast;
        while(itr){
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
}