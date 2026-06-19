class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}

        int max_0 = nums[0]; int max_1 = max(max_0,nums[1]);
        int max_f = max(max_0,max_1);
        
        for(int i=2; i<nums.size();i++){
            max_f = max(nums[i]+max_0,max_1);
            int temp = max_1;
            max_1 = max_f;
            max_0 = temp;
        }
        return max_f;
    }
};
