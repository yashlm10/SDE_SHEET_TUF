#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

void deleteNodemysol(ListNode* node) {
        ListNode* temp = node;
        while(temp->next->next){
           temp->val = temp->next->val;
           temp = temp->next;
        }
        temp->val = temp->next->val;
        temp->next = NULL;

    }

void deleteNodeoptimal(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }

int main(){
    int n;
    cin >> n;
    ListNode* head1 = new ListNode(n);
    ListNode* temp1 = head1;
    while(cin >> n){
        if(n==-1)break;
        ListNode* curr = new ListNode(n);
        temp1->next = curr;
        temp1 = curr;
    }
    int value;
    cin >> value;
    ListNode* node = head1;
    while(node->val != value) node = node->next;
    deleteNodeoptimal(node);
     ListNode* print = head1;
    while(print){
        cout << print->val << " ";
        print = print->next;
    }
    cout << endl;
    return 0;

}