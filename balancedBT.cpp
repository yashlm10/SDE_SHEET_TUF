#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int balanceMysol(TreeNode* root, bool &bal){
       if(!root)return 0;

       int lh = balanceMysol(root->left, bal);
       int rh = balanceMysol(root->right, bal);
       if(max(lh,rh) - min(lh,rh) > 1){
           bal = 0;
       }
       return 1 + max(lh,rh);
    }
bool isBalancedMysol(TreeNode* root) {
    bool bal = true;
    balanceMysol(root,bal);
    return bal;
}


int balance(TreeNode* root){
       if(!root)return 0;

       int lh = balance(root->left);
       if(lh == -1) return -1;

       int rh = balance(root->right);
       if(rh == -1) return -1;

       if(abs(lh-rh) > 1){
           return -1;
       }
       return 1 + max(lh,rh);
    }
bool isBalanced(TreeNode* root) {
    return balance(root) != -1;
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

    bool blns = isBalancedMysol(root);
    cout << blns << endl;

    return 0;
}