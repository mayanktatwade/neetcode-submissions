class Solution {
public:
int n;
    void helper(vector<bool>&dp, int idx,vector<int>& nums){
        if(dp[idx]){return;}
        if(idx>=n){return;}

        dp[idx] = true;
        int temp = nums[idx];
        while(temp>0){
        helper(dp,idx+temp,nums);
        temp--;
        }
        return;
    }
    bool canJump(vector<int>& nums) {
        int n_ = nums.size();
        n = n_;
        vector<bool>dp(n,false);

        helper(dp,0,nums);
        if(dp[n-1]){return true;}
        return false;

    }
};
