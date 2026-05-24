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
public:
    vector<vector<int>>ans;

    void traverse(TreeNode*root,int depth){
        if(root == NULL){return;}
        else if(ans.size()==depth){
            ans.push_back({root->val});
        }
        else{
            ans[depth].push_back(root->val);
        }
        traverse(root->left,depth+1);
        traverse(root->right,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // if(root == NULL){return {};}
        traverse(root,0);
        return ans;
    }
};
