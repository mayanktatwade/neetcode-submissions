class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l=0; int r=0; 

        int ans = INT_MAX;

        int total = 0;

        while(r<n && total<target){total+=nums[r];r++;}r--;
        if(total<target){return 0;}


        while(r<n && l<=r){
            // total+=nums[r];
            if(total<target){r++; if(r<n){total+=nums[r]-nums[l]; l++;}}
            else{
                ans = min(ans,r-l+1);
                if(total-nums[l]>=target){total-=nums[l];l++;}
                else{r++; if(r<n){total+=nums[r]-nums[l]; l++;}}
            }
        }

        return ans;
    }
};