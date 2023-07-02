#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> preOrderTraversalIterative(TreeNode* root) {
        vector<int> answer;
        stack <TreeNode*> s;
       if(root == NULL)return answer;
       s.push(root);
       while(!s.empty()){
           TreeNode* curr = s.top();
           answer.push_back(curr->val);
           s.pop();
           if(curr->right != NULL) s.push(curr->right);
           if(curr->left != NULL) s.push(curr->left);
       }
       return answer;
}

void preOrderHelper(TreeNode* root, vector<int>&answer){
        if(root==NULL)return;

        answer.push_back(root->val);
        preOrderHelper(root->left, answer);
        preOrderHelper(root->right, answer);
    }
vector<int> preOrderTraversalRecurr(TreeNode* root) {
        vector<int> answer;
        preOrderHelper(root, answer);
        return answer;
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

    vector<int> preOrder = preOrderTraversalRecurr(root);
    for(int i=0;i< preOrder.size(); i++){
        cout << preOrder[i] << " ";
    }
    return 0;
}