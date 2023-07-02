#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> bottom_view(TreeNode* root){
    vector<int> answer;
    if(root == NULL)  return answer;
    map<int,int> mpp;
    queue<pair<TreeNode*, int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int line = it.second;
        TreeNode* temp = it.first;
        mpp[line] = temp->val;
        if(temp -> left != NULL) q.push({temp->left,line-1});
        if(temp -> right != NULL) q.push({temp->right,line+1});
    }

    for(auto it: mpp){
        answer.push_back(it.second);
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

    vector<int> bottomview = bottom_view(root);
    for(int i=0;i< bottomview.size(); i++){
        cout << bottomview[i] << " ";
    }
    
    return 0;
}