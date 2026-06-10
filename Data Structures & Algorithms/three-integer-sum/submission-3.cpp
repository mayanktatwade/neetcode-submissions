class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums,int l, int r,int target){
        vector<vector<int>> ans;int temp;
        while(l<r){
            if(nums[l]+nums[r]==target){
                ans.push_back({nums[l],nums[r]});
                int temp = nums[r--];
                while(l < r &&  nums[r]==temp){
                    temp = nums[r--];
                }
                temp = nums[l++];
                while(l < r && nums[l]==temp){
                    temp = nums[l++];
                }
            }
            else if(nums[l]+nums[r]>target){
                temp = nums[r--];
                while(l < r && nums[r]==temp){
                    temp = nums[r--];
                }
            }
            else{
                temp = nums[l++];
                while(l < r && nums[l]==temp){
                    temp = nums[l++];
                }
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int pointer = 0;
        // int l=1;int r = nums.size()-1;

        while(pointer<nums.size()-2){
            int target = -1*nums[pointer];
            vector<vector<int>>temp = twoSum(nums,pointer+1,nums.size()-1,target);
            if(temp.size()){
                for(vector<int>i:temp){
                    i.push_back(nums[pointer]);
                    ans.push_back(i);
                }
            }
            int a = nums[pointer];
            while(pointer < nums.size() && nums[pointer]==a){
                a=nums[pointer++];
            }
        }
        return ans;
    }
};
