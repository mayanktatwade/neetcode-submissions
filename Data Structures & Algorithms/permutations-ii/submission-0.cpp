class Solution {
public:
int n;
    void helper(vector<int>&nums, vector<int>&curr,
    vector<vector<int>>&ans, set<vector<int>>&st, int size,set<int>&indexes){
        if(size == n){if(!st.count(curr)){ans.push_back(curr);st.insert(curr);}}

        for(int i = 0; i<n; i++){
            if(!indexes.count(i)){
                curr.push_back(nums[i]);
                size++; indexes.insert(i);
                helper(nums,curr,ans,st,size,indexes);
                curr.pop_back();size--;
                indexes.erase(i);
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();vector<int>curr; vector<vector<int>>ans;
        set<vector<int>>st; set<int>indexes;
        helper(nums,curr,ans,st,0,indexes);
        return ans;
    }
};