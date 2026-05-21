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
    int depth(TreeNode* root){
        if(root == NULL){return 0;}

        int l = depth(root->left);
        int r = depth(root->right);
        // cout<<1+max(l,r)<<endl;

        return 1+max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL || depth(root)==1){return true;} 
        int left = depth(root->left);
        int right = depth(root->right);
        // cout<<left<<" "<<right<<endl;
        if(abs(right-left)>1){return false;}
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
