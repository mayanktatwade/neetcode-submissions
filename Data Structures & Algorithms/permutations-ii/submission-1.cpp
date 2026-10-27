
class Solution {
public:
    int n;

    void helper(vector<int>& nums, vector<int>& curr,
                vector<vector<int>>& ans, vector<bool>& used) {
        
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(used[i]) continue;

            // Skip duplicate choices at the same recursion level
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;

            curr.push_back(nums[i]);
            used[i] = true;

            helper(nums, curr, ans, used);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(n, false);

        helper(nums, curr, ans, used);
        return ans;
    }
};

// class Solution {
// public:
// int n;
//     void helper(vector<int>&nums, vector<int>&curr,
//     vector<vector<int>>&ans, set<vector<int>>&st, int size,set<int>&indexes){
//         if(size == n){if(!st.count(curr)){ans.push_back(curr);st.insert(curr);}}

//         for(int i = 0; i<n; i++){
//             if(!indexes.count(i)){
//                 curr.push_back(nums[i]);
//                 size++; indexes.insert(i);
//                 helper(nums,curr,ans,st,size,indexes);
//                 curr.pop_back();size--;
//                 indexes.erase(i);
//             }
//         }
//         return;
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         n = nums.size();vector<int>curr; vector<vector<int>>ans;
//         set<vector<int>>st; set<int>indexes;
//         helper(nums,curr,ans,st,0,indexes);
//         return ans;
//     }
// };