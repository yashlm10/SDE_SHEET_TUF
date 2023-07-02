#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int max_width(TreeNode* root){
    if(!root) return 0; 
    int ans =0;
    queue<pair<TreeNode*, long long>>q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int curr_min = q.front().second;
        int leftmost,rightmost;
        for(int i=0;i<size;i++){
            long long curr_id = q.front().second - curr_min;
            TreeNode* temp = q.front().first;
            q.pop();
            if(i==0) leftmost = curr_id;
            if(i == size-1) rightmost = curr_id;
            if(temp->left){
                q.push({temp->left, 2*curr_id +1});
            }
            if(temp->right){
                q.push({temp->right, 2*curr_id +2});
            }
        }
        ans = max(ans, rightmost-leftmost+1);
        
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

    int maxWidth = max_width(root);
    cout << maxWidth << endl;
    return 0;
}