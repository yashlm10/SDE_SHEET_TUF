#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

bool hasCycleMysol(ListNode *head) {
        int x = INT_MIN;
        ListNode* temp = head;
        bool a = 1;
        if(!temp)return 0;
        while(a){
            if(temp->data == x){
                a = 0;
            }
            temp->data = x;
            temp = temp -> next;
            if(!temp)break;
        }
        if(a)return 0;
        else return 1;
}

bool hasCycleHash(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* temp = head;
        if(!temp)return 0;
        while(temp){
            if(st.find(temp) != st.end()){
                return 1;
            }else{
                st.insert(temp);
                temp=temp->next;
            }
        }
        return 0;
}

bool hasCycleHareTort(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head)return 0;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)return 1;
        }
       return 0;
}

void createCycle(ListNode* &head,int a,int b) {
    int cnta = 0,cntb = 0;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
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
    int a,b;
    cin >> a >> b;
    createCycle(head1,a,b);
    bool ans1 = hasCycleMysol(head1);
    bool ans2 = hasCycleHash(head1);
    bool ans3 = hasCycleHareTort(head1);
    if(ans1)cout<< "true"<<endl;
    else cout << " false" << endl;

    return 0;
}