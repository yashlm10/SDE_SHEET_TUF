#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> printLvls(TreeNode* root){
    vector<vector<int>> ans;
    if(!root)return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int>subs;
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            subs.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        ans.push_back(subs);
    }
    return ans;
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

    vector<vector<int>>answer =  printLvls(root);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}