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
    bool ans = true;
    void traverse(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL){if(p != NULL || q != NULL){ans=false;}
        return;}
        else if(p->val!=q->val){ans = false; return;}
        else{
        traverse(p->left,q->left);
        traverse(p->right,q->right);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p,q);
        return ans;
    }
};
