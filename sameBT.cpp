#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSame(TreeNode* p, TreeNode* q){
   if(!p && !q)return true;
   if(!p || !q)return false;

   return(p->val == q->val && isSame(p->left,q->left) && isSame(p->right,q->right));
}

int main(){
    TreeNode * p = new TreeNode(1);
    p -> left = new TreeNode(2);
    p -> right = new TreeNode(3);
    p -> left -> left = new TreeNode(4);
    p -> left -> right = new TreeNode(5);
    p -> left -> right -> left = new TreeNode(8);
    p -> right -> left = new TreeNode(6);
    p -> right -> right = new TreeNode(17);
    p -> right -> right -> left = new TreeNode(9);
    p -> right -> right -> right = new TreeNode(10);

    TreeNode * q = new TreeNode(1);
    q -> left = new TreeNode(2);
    q -> right = new TreeNode(3);
    q -> left -> left = new TreeNode(4);
    q -> left -> right = new TreeNode(5);
    q -> left -> right -> left = new TreeNode(8);
    q -> right -> left = new TreeNode(6);
    q -> right -> right = new TreeNode(7);
    q -> right -> right -> left = new TreeNode(9);
    q -> right -> right -> right = new TreeNode(10);

    cout << isSame(p,q) << endl;

    return 0;
}