#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

 ListNode* removeNthFromEndbrute(ListNode* head, int n) {
        int cnt =0;
        ListNode* temp = head;
        if(!head)return head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        if(cnt==n)return head->next;
        
        cnt = cnt - n -1;
        temp = head;
        int cnt1 =0;
        while(temp){
            if(cnt1 == cnt){
              temp->next = temp->next->next;
            }
            cnt1++;
          temp = temp->next;
        }
        
        return head;
    }

 ListNode* removeNthFromEndtwoptr(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start -> next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        
        while(n--){
            fast = fast->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
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
    int pos;
    cin >> pos;
    ListNode* print = removeNthFromEndtwoptr(head1, pos);
    while(print){
        cout << print->val << " ";
        print = print->next;
    }
    cout<< endl;
    return 0;
}
