#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        int j = k-1;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr;
        ListNode* prev = dummy;
        ListNode* nxt;
        while(cnt>=k){
            curr = prev->next;
            nxt = curr->next;
            while(j--){
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            j = k-1;
            prev = curr;
            cnt -= k;
        }
        return dummy->next;

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
    int k;
    cin >> k;
    ListNode* print = reverseKGroup(head1, k);
    while(print){
        cout << print->data << " ";
        print = print->next;
    }
    cout << endl;
    return 0;
}