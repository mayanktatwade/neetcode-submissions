class Solution {
public:
    int sum_vec(vector<int>& nums){
        int total = 0;
        for(int i :nums){
            total = total+i;
        }
        return total;
    }
    void helper(vector<int>& nums,int target,vector<int>& temp,vector<vector<int>>&ans,int idx, bool flag){
        if(idx==nums.size()){return;}

        int sum = sum_vec(temp);

        if(sum==target){ans.push_back(temp);flag = false;return;}
        if(sum>target){flag = false;return;}

        flag = true;

        int i = idx;
        while(flag && i<nums.size()){
            temp.push_back(nums[i]);
            helper(nums,target,temp,ans,i,flag);
            temp.pop_back();
            i++;
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp; vector<vector<int>>ans;
        helper(nums,target, temp,ans,0, true);

        return ans;
    }
};
