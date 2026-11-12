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
 #include <map>
class Solution {
public:

    int helper(TreeNode* root, bool allowed, map<pair<TreeNode*,bool>,int>& mp){
        if(root==nullptr){return 0;}
        if(mp.count({root,allowed})){return mp[{root,allowed}];}

        int ans1 = 0; int ans2 = 0;
        if(allowed){
            ans1 = root->val + helper(root->left,false,mp) + helper(root->right,false,mp);
        }
        ans2 = helper(root->left, true,mp) + helper(root->right,true,mp);

        mp[{root,allowed}] = max(ans1,ans2);
        return max(ans1,ans2);

    }

    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int>mp;
       return helper(root,true,mp);
    }
};