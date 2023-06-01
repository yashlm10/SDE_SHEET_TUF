#include <bits/stdc++.h>
using namespace std;
 
struct ListNode{
     int data;
     struct ListNode* next;
     ListNode() : data(0), next(nullptr) {}
     ListNode(int x) : data(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : data(x) , next(next) {}
};

ListNode* middleNodeHareTort(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

ListNode* middleNodebrute(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        ListNode* mdl = head;
        cnt /= 2;
       // if(!cnt%2)cnt--;
        while(cnt--){
          mdl = mdl->next;
        }
        return mdl;
    }

int main(){
    int value;
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* temp = head;
    while(cin >> value){
        ListNode* ctemp = new ListNode(value);
        temp->next = ctemp;
        temp = ctemp;
    }
    ListNode* print = middleNodebrute(head);
    while(print){
        cout << print->data << " ";
        print = print->next;
    }
    cout << endl;
}