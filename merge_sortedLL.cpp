#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* mergeTwoListsInplace(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        if(list1->val > list2->val) swap(list1,list2);

        ListNode* ans = list1;
        while(list1 && list2){
            ListNode* temp = NULL;
            while(list1 && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return ans;
    }

ListNode* mergeTwoListsExtrasc(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* ddum = dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                
                ddum->next = list1;
                list1 = list1->next;
            }else{
                
                ddum->next = list2;
                list2 = list2->next;
            }
            ddum = ddum->next;
        }
        if(list1){
             ddum->next = list1;
        }
        if(list2){
            ddum->next = list2;   
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
    ListNode* print = mergeTwoListsExtrasc(head1, head2);
    while(print){
        cout << print->val << " ";
        print = print->next;
    }
    cout << endl;
    return 0;
}
