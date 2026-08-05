class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1){return nums[0];}
        int l = 0; int r = 0;
        int total = 0; int ans = INT_MIN;
        
        while(r<n){
            total += nums[r++];
            ans = max(total,ans);
            if(total<=0){total = 0;}
        }
        return ans;
    }
};
