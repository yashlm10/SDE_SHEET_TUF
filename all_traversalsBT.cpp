#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> all_traversals(TreeNode* root){
    vector<vector<int>> answer;
    vector<int> pre,in,post;
    if(root == NULL)return answer;
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});
    while(!s.empty()){
       pair<TreeNode*,int> p = s.top();
       s.pop();
       if(p.second == 1){
         p.second++;
         pre.push_back(p.first -> val);
         s.push(p);

         if(p.first ->left != NULL){
            s.push({p.first->left,1});
         }
       }else if(p.second == 2){
         p.second++;
         in.push_back(p.first -> val);
         s.push(p);

         if(p.first ->right != NULL){
            s.push({p.first->right,1});
         }
       }else 
         post.push_back(p.first -> val);
    }
    answer.push_back(pre);
    answer.push_back(in);
    answer.push_back(post);
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

    vector<vector<int>> ans = all_traversals(root);

    for(int i=0;i < ans.size();i++){
        for(int j=0;j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}