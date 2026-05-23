/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
vector<int>ans;

void traverse(TreeNode* root,int depth){
    if(root == NULL){return;}
    if(ans.size()== depth){
        ans.push_back(-1);
        ans[depth] = root->val;}
    traverse(root->right,depth+1);
    traverse(root->left,depth+1);
    return;
}

public:
    vector<int> rightSideView(TreeNode* root) {
        traverse(root,0);
        return ans;
    }
};
