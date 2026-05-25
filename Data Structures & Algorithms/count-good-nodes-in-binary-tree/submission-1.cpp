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
    int ans = 0;

    void traverse(TreeNode* root, int maxtillnow) {
        if (root == NULL) {
            return;
        }
        if (root->val >= maxtillnow) {
            ans++;
            maxtillnow = root->val;
        }
        traverse(root->left, max(root->val, maxtillnow));
        traverse(root->right, max(root->val, maxtillnow));
        return;
    }

    int goodNodes(TreeNode* root) {
        traverse(root, root->val);
        return ans;
    }
};
