class Solution {
public:
    int ans = 0;
    void helper(vector<int>& nums, int& target, vector<int>& sum, int idx, int currsum){
        if(idx>nums.size()){return;}
        if(idx==nums.size() && currsum==target){ans++; return;}
        if(currsum+sum[idx]<target){return;}
        if(currsum-sum[idx]>target){return;}

        helper(nums,target,sum,idx+1,currsum+nums[idx]);
        helper(nums,target,sum,idx+1,currsum-nums[idx]);

        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int>sum(nums.size()+1);
        sort(nums.begin(),nums.end());
        int temp = 0;int idx = 0;
        
        for(int i = nums.size()-1; i>=0; i--){
            temp+=nums[i];
            sum[i] = temp;
        }
        helper(nums,target,sum,0,0);

        return ans;
    }
};
