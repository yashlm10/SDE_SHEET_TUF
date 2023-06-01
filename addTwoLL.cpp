#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry =0;
        while(l1 || l2 || carry){
            int sum =0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            sum %= 10;
            ListNode* digit = new ListNode(sum);
            temp->next = digit;
            temp = temp->next;
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
    int m;
    cin >> m;
    ListNode* head2 = new ListNode(m);
    ListNode* temp2 = head2;
    while(cin >> m){
        ListNode* curr = new ListNode(m);
        temp2->next = curr;
        temp2 = curr;
    }
    ListNode* print = addTwoNumbers(head1, head2);
    while(print){
        cout << print->val << " ";
        print = print->next;
    }
    cout << endl;
    return 0;
}