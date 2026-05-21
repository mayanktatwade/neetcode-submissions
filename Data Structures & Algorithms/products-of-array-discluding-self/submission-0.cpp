class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_index;
        int zero_count = 0; int product = 1;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]==0){zero_index= i; zero_count++;}
            else{product*= nums[i];}
        }

        
        if(zero_count==0){
            vector<int>result;
            for(int i=0;i<nums.size();i++){
                result.push_back(product/nums[i]);
            }
            return result;
        }
        if(zero_count==1){
            vector<int> v(nums.size(), 0);
            v[zero_index] = product;
            return v;
        }
        if(zero_count>1){
            vector<int> v(nums.size(), 0);
            return v;
        }
    }
};
