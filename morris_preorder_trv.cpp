#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> preOrderTraversalMorris(TreeNode* root){
       vector<int>answer;
       while(root != NULL){
        if(root -> left == NULL){
            answer.push_back(root->val);
            root = root -> right;
        }else{
            TreeNode* pre = root -> left;
            while(pre -> right != NULL && pre->right != root){
                pre = pre->right;
            }

            if(pre -> right == NULL){
                pre->right = root;
                answer.push_back(root->val);
                root = root ->left;
            }else{
                pre -> right = NULL;
                root = root -> right;
            }
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

    vector<int> preOrder = preOrderTraversalMorris(root);
    for(int i=0;i< preOrder.size(); i++){
        cout << preOrder[i] << " ";
    }
    return 0;
}