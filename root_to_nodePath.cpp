#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool root_node(TreeNode *root, vector<int> &answer, int x){
   if(root == NULL)return false;
   
   answer.push_back(root->val);

   if(root->val == x) return true;

   if(root_node(root->left,answer,x) || root_node(root->right, answer, x))return true;

   answer.pop_back();
   return false;

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
    
    int x;
    cin >> x;
    vector<int> rootToNode;
    root_node(root, rootToNode, x);
    for(int i=0;i< rootToNode.size(); i++){
        cout << rootToNode[i] << " ";
    }
    
    return 0;
}