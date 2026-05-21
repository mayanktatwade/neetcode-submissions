class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size);
        vector<int> right(size);

        int l_prod = 1;
        int r_prod = 1;
        for (int i = 0; i < size; i++) {
            l_prod = l_prod * nums[i];
            r_prod = r_prod * nums[size - i - 1];

            left[i] = l_prod;
            right[size - i - 1] = r_prod;
        }

        vector<int> ans(size);
        ans[0] = right[1];
        ans[size-1]=left[size-2];
        for(int i =1; i<size-1 ; i++){
            ans[i] = left[i-1]*right[i+1];
        }
        return ans;
    }
};
