class Solution {
public:
    int sum_vec(vector<int>nums){
        int target = 0;
        for(int i:nums){
            target = target+i;
        }return target;
    }
    void helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>temp,int idx){


        int sum = sum_vec(temp);
        if(sum==target){ans.push_back(temp);return;}
        if(sum>target){return;}
        if(idx == candidates.size()){return;}
        
        for(int i = idx; i<candidates.size(); i++ ){
            if(i>idx && candidates[i]==candidates[i-1]){continue;}

            temp.push_back(candidates[i]);
            helper(candidates,target,ans,temp, i+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp; 
        helper(candidates,target,ans,temp, 0 );
        return ans;
    }
};
