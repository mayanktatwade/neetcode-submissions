
class Solution {
public:
    void helper(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>&final){
        if(i == nums.size()){
            final.push_back({ans});
            return ;
        }

        
        ans.push_back(nums[i]);
        helper(nums,ans,i+1,final);
        ans.pop_back();

        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        helper(nums,ans,idx,final);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>final;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i:nums){cout<<i<<" ";}
        helper(nums,ans,0,final);
        return final;
    }
};
