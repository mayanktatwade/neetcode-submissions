#include <algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp; int len=1;
        temp.push_back(nums[0]);

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]); len++;
            }
            else{
                int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
    }
};


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int>dp(nums.size(),1); int temp; int ans = 1;
//         dp[nums.size()-1]=1;
//         for(int i = nums.size()-2; i>=0; i--){
//             temp = 1;
//             for(int j = i+1; j<nums.size(); j++){
//                 if(nums[j]>nums[i]){
//                     temp = max(temp,dp[j]+1);
//                 }
//             }
//             dp[i]=temp;
//             ans = max(ans,dp[i]);
//         }

//         // if(ans)
//         return ans;
//     }
// };