class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans, vector<int> temp ){
        if(nums.size()==0){ans.push_back(temp);return;}

        for(int i = 0; i<nums.size(); i++){
            temp.push_back(nums[i]);
            vector<int> copy = nums;
            copy.erase(copy.begin()+i);
            helper(copy,ans,temp);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;vector<int> temp ;
        helper(nums,ans, temp );
        return ans;
    }
};
