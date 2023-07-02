#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void leftviewhelp(TreeNode* root, int level, vector<int> &answer){
    if(root == NULL)return;
    
    if(answer.size() == level)answer.push_back(root->val);
    leftviewhelp(root->left, level+1, answer);
    leftviewhelp(root->right, level+1, answer);
}
vector<int> left_view(TreeNode* root){
    vector<int> answer;
    leftviewhelp(root, 0, answer);
    return answer;
}

void rightviewhelp(TreeNode* root, int level, vector<int> &answer){
    if(root == NULL)return;
    
    if(answer.size() == level)answer.push_back(root->val);
    rightviewhelp(root->right, level+1, answer);
    rightviewhelp(root->left, level+1, answer);
}
vector<int> right_view(TreeNode* root){
    vector<int> answer;
    rightviewhelp(root, 0, answer);
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

    vector<int> leftview = left_view(root);
    for(int i=0;i< leftview.size(); i++){
        cout << leftview[i] << " ";
    }
    cout << endl;
    vector<int> rightview = right_view(root);
    for(int i=0;i< rightview.size(); i++){
        cout << rightview[i] << " ";
    }
    return 0;
}