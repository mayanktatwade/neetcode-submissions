// class Solution {
// public:
//     void helper(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>&final){
//         if(i == nums.size()){
//             final.push_back({ans});
//             return ;
//         }
//         ans.push_back(nums[i]);
//         helper(nums,ans,i+1,final);
//         ans.pop_back();
//         helper(nums,ans,i+1,final);
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>final;
//         vector<int>ans;
//         helper(nums,ans,0,final);
//         return final;
//     }
// };
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    //    int pointer = 0;
        vector<vector<int>>ans;vector<vector<int>>temp; vector<int> temp1;
        ans.push_back({});
        ans.push_back({nums[0]});

        for(int i=1; i<nums.size(); i++){
            temp = {};temp1 = {};
            for(vector<int> v:ans){
                temp1 = v;
                temp1.push_back(nums[i]);
                temp.push_back(temp1);
            }ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
};
