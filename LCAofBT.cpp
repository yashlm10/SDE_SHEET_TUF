#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* lcaOfBt(TreeNode* root,TreeNode* p,TreeNode* q){
    if(!root || root == p || root == q) return root;

    TreeNode* leftst = lcaOfBt(root->left,p,q);
    TreeNode* rightst = lcaOfBt(root->right,p,q);

    if(!leftst)return rightst;
    else if(!rightst)return leftst;
    else return root;
}

int main(){
    TreeNode * root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> left -> right -> left = new TreeNode(8);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    root -> right -> right -> left = new TreeNode(9);
    root -> right -> right -> right = new TreeNode(10);

    TreeNode * p = root -> left->left;
    TreeNode * q = root -> left->right;

    TreeNode* lca = lcaOfBt(root,p,q);
    cout << lca->val << endl;

    return 0;
}