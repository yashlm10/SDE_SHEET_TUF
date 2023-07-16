#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int findDiameter(TreeNode* root, int &diameter){
        if(!root)return 0;
        int lh = findDiameter(root->left, diameter);
        int rh = findDiameter(root->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1 + max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDiameter(root,diameter);
        return diameter;
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

    int diameter = diameterOfBinaryTree(root);
    cout << diameter << endl;

    return 0;
}