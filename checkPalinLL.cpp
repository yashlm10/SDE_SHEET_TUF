#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool isPalindromeExtrasc(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        for(int i=0;i<n/2;i++){
            if(v[i]!=v[n-1-i]) return 0;
        }
        return 1;
}

bool isPalindromeOptimal(ListNode* head) {
        if(!head || !head->next)return 1;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev = slow;
        ListNode* nxt = curr->next;
        while(nxt){
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = slow->next;
        while(temp2){
            if(temp1->val != temp2 -> val)return 0;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return 1;

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
    bool ans = isPalindromeOptimal(head1);
    if(ans)cout << "yes" << endl;
    else cout << " no" << endl;
    return 0;
}