class Solution {
public:
    void helper(vector<int>& candidates,
                int target,                  // remaining target
                vector<vector<int>>& ans,
                vector<int>& temp,
                int idx) {

        // Found a valid combination
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Try each candidate starting from idx
        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            // Example: [1,1,2]
            // If we already explored the first 1 at this level,
            // don't explore the second 1.
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted, no need to continue
            // if current number exceeds remaining target.
            if (candidates[i] > target) {
                break;
            }

            // Choose current element
            temp.push_back(candidates[i]);

            // Move to next index because each element
            // can be used at most once.
            helper(candidates,
                   target - candidates[i],
                   ans,
                   temp,
                   i + 1);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // Sorting is required for:
        // 1. Duplicate skipping
        // 2. Early stopping (break)
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        helper(candidates, target, ans, temp, 0);

        return ans;
    }
};
// class Solution {
// public:
//     int sum_vec(vector<int>nums){
//         int target = 0;
//         for(int i:nums){
//             target = target+i;
//         }return target;
//     }
//     void helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>temp,int idx){


//         int sum = sum_vec(temp);
//         if(sum==target){ans.push_back(temp);return;}
//         if(sum>target){return;}
//         if(idx == candidates.size()){return;}
        
//         for(int i = idx; i<candidates.size(); i++ ){
//             if(i>idx && candidates[i]==candidates[i-1]){continue;}

//             temp.push_back(candidates[i]);
//             helper(candidates,target,ans,temp, i+1);
//             temp.pop_back();
//         }
//         return;
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>>ans;
//         vector<int>temp; 
//         helper(candidates,target,ans,temp, 0 );
//         return ans;
//     }
// };
