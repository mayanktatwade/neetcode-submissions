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
    bool same = true;

    void traverse(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL){if(p!=NULL || q!= NULL){same = false;}
        return;}
        else if(p->val != q->val){same = false; return;}
        else{
            traverse(p->left,q->left);
            traverse(p->right,q->right);
        }
    }
    bool isSame(TreeNode* p, TreeNode* q){
        traverse(p,q);
        bool final = same;
        same =true;
        return final;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==NULL || subroot==NULL){if(root!=subroot){return false;}
        return true;}
        if(root->val == subroot->val && isSame(root, subroot)){
            return true;
        }
        else {bool b1 = isSubtree(root->left, subroot);
        bool b2 = isSubtree(root->right, subroot);
        return b1||b2;}
    }
};
