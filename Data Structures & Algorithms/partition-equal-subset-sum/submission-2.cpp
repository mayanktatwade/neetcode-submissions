class Solution {
public:
bool ans = false;

    void helper(vector<int>& nums, int idx, int sum,int & target){
        if(ans){return;}
        if(idx>=nums.size()){return;}
        if(sum>target){return;}
        if(sum==target){ans = true; return;}

        for(int i = idx+1; i<nums.size(); i++){
            if(sum+nums[i]>target){break;}
            helper(nums,i,sum+nums[i],target);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums){sum+=i;}
        if(sum%2==1){return false;}
        sum = sum/2;
        sort(nums.begin(),nums.end());
        helper(nums,0,nums[0],sum);
        return ans;
    }
};
