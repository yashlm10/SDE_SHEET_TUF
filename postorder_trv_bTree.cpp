#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void postorderhelper(TreeNode* root, vector<int> &answer){
    if(root == NULL)return;

    postorderhelper(root->left, answer);
    postorderhelper(root->right, answer);
    answer.push_back(root->val);
}
vector<int> postOrderTraversalRecurr(TreeNode* root){
    vector<int> answer;
    postorderhelper(root, answer);
    return answer;
}

vector<int> postOrderTraversaltwoStacks(TreeNode* root){
    vector<int> answer;
    if(root==NULL)return answer;

    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);
    while(!s1.empty()){
        TreeNode* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left != NULL) s1.push(temp->left);
        if(temp->right != NULL) s1.push(temp->right);
    }
    while(!s2.empty()){
        answer.push_back(s2.top() -> val);
        s2.pop();
    }
    return answer;
}

vector<int> postOrderTraversaloneStack(TreeNode* root){
    vector<int> answer;
    if(root==NULL)return answer;

    stack <TreeNode*> s;
    while(root != NULL || !s.empty()){
        if(root != NULL){
            s.push(root);
            root = root -> left;
        }else{
            TreeNode* temp = s.top()->right;
            if(temp == NULL){
                 temp = s.top();
                 s.pop();
                 answer.push_back(temp->val);
                 while(!s.empty() && s.top()->right == temp){
                    temp = s.top();
                    s.pop();
                    answer.push_back(temp->val);
                 }
            }else root = temp;
        }
    }
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

    vector<int> postOrder = postOrderTraversaltwoStacks(root);
    for(int i=0;i< postOrder.size(); i++){
        cout << postOrder[i] << " ";
    }
    return 0;
}