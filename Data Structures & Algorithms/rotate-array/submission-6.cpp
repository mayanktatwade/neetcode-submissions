class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        k=n-k;
        int t = k;
        int idx = 0; 
        while(k){
            nums.push_back(nums[idx++]);k--;
        }
        nums = vector<int>(nums.begin()+t,nums.end());
    }
};