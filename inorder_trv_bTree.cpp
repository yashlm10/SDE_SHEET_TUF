#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void inorderHelper(TreeNode* root, vector<int>&answer){
    if(root == NULL) return;

    inorderHelper(root -> left, answer);
    answer.push_back(root->val);
    inorderHelper(root->right, answer);
}
vector<int> inOrderTraversalRecurr(TreeNode* root){
    vector<int> answer;
    inorderHelper(root, answer);
    return answer;
}

vector<int> inOrderTraversalIterative(TreeNode* root){
     vector<int> answer;
     stack<TreeNode*> s;
     while(1){
        if(root != NULL){
            s.push(root);
            root = root->left;
        }else{
            if(s.empty())break;
            root = s.top();
            answer.push_back(root -> val);
            s.pop();
            root = root->right;
        }
     }
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

    vector<int> inOrder = inOrderTraversalRecurr(root);
    for(int i=0;i< inOrder.size(); i++){
        cout << inOrder[i] << " ";
    }
    return 0;
}