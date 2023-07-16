#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int heightRecurr(TreeNode* root){
    if(!root)return 0;
    int lefth = heightRecurr(root->left);
    int righth = heightRecurr(root->right);
    return 1 + max(lefth, righth);
}

int heightofBT(TreeNode* root){
    if(!root)return 0;
    queue<TreeNode*> q;
    q.push(root);
    int cnt =0;
    while(!q.empty()){
        
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        cnt++;
    }
    return cnt;
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

    int height = heightRecurr(root);
    cout << height << endl;

    return 0;
}