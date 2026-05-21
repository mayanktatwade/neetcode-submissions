class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        if(size ==0 || size ==1){return false;}

        for(int i = 0 ;i<size-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
    
};