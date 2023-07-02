#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> vertical_order_traversal(TreeNode* root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push({root, {0,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* temp = it.first;

        int x = it.second.first, y = it.second.second;
        nodes[x][y].insert(temp->val);

        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
        if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> answer;
    for(auto p: nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        answer.push_back(col);
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

    vector<vector<int>> ans = vertical_order_traversal(root);

    for(int i=0;i < ans.size();i++){
        for(int j=0;j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}