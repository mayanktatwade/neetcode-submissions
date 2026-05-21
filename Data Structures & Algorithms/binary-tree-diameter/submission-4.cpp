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
int maximum=0;
    int maxDepth(TreeNode* root){
        if(root == NULL){return 0;}

        int temp1 =maxDepth(root->left);
        int temp2 =maxDepth(root->right);

        maximum = max(temp1+temp2,maximum);
        return 1+max(temp1,temp2);        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maximum;
        
    }
};
