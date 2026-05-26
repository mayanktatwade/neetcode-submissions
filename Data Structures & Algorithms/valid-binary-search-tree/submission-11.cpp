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
vector<int> ans;
    void traverse(TreeNode* root){
        if(root==NULL){return;}

        traverse(root->left);
        ans.push_back(root->val);
        traverse(root->right);

        return;
    
    }
    bool isValidBST(TreeNode* root) {
        traverse(root);

        if(ans.size()<=1){return true;}
        for(int i = 1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]){return false;}
        }
        return true;
    }
};
