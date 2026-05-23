// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// vector<int>ans;

// void traverse(TreeNode* root,int depth){
//     if(root == NULL){return;}
//     if(ans.size()== depth){
//         ans.push_back(root->val);
//         // ans[depth] = root->val;
//         }
//     traverse(root->right,depth+1);
//     traverse(root->left,depth+1);
//     return;
// }

// public:
//     vector<int> rightSideView(TreeNode* root) {
//         traverse(root,0);
//         return ans;
//     }
// };
class Solution {
    void traverse(TreeNode* root, int depth, vector<int>& ans) {
        if (!root) return;

        if (ans.size() == depth) {
            ans.push_back(root->val);
        }

        traverse(root->right, depth + 1, ans);
        traverse(root->left, depth + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, 0, ans);
        return ans;
    }
};