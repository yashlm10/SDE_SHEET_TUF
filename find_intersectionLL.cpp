#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

ListNode *getIntersectionNodeBrute(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        while(tempA){
            while(tempB){
                if(tempA == tempB)return tempB;
                tempB = tempB->next;
            }
            tempA = tempA->next;
            tempB = headB;
        }
        return NULL;
}
 
ListNode *getIntersectionNodeHash(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA){
            st.insert(tempA);
            tempA = tempA->next;
        }
        while(tempB){
            if(st.find(tempB) != st.end()) return tempB;
            tempB=tempB->next;
        }
        return NULL;
}

ListNode *getIntersectionNodeDiff(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int cntA=0,cntB=0;
        while(tempA->next){
            cntA++;
            tempA = tempA->next;
        }
        tempA = headA;
        while(tempB->next){
            cntB++;
            tempB = tempB->next;
        }
        tempB=headB;
        int diff = max(cntA,cntB)-min(cntA,cntB);
        if(cntA>cntB){
           while(diff--){
             tempA=tempA->next;
           }
        }else{
            while(diff--){
             tempB=tempB->next;
           }
        }
        while(tempA){
            if(tempA==tempB)return tempA;
              tempA=tempA->next;
              tempB=tempB->next;
        }
        return NULL;
}

ListNode *getIntersectionNodeOptimal(ListNode *headA, ListNode *headB) {
        ListNode* tA = headA;
        ListNode* tB = headB;
        bool a = 0,b = 0;
        while(tA != tB){
            if(!tA){
                if(a)return NULL;
                tA = headB;
                a = 1;
                tB=tB->next;
                continue;
            }
            if(!tB){
                if(b)return NULL;
                tB = headA;
                b = 1;
                tA=tA->next;
                continue;
            }
             tA=tA->next;
             tB=tB->next;
        }
        return tA;
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
    ListNode* intersection = getIntersectionNodeBrute(head1,head2);
    cout << intersection->data << endl;

    ListNode* intersection2 = getIntersectionNodeHash(head1,head2);
    cout << intersection2->data << endl;

    ListNode* intersection3 = getIntersectionNodeDiff(head1,head2);
    cout << intersection3->data << endl;
    
    ListNode* intersection4 = getIntersectionNodeOptimal(head1,head2);
    cout << intersection4->data << endl;
    return 0;
}