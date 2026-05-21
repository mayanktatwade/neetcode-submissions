class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i = 0; i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        // vector<vector<int>> result;

        int left = 0; int right = nums.size()-1;


        while(left<right){
            int sum = arr[left].first+arr[right].first;
            if(sum == target){
                if(arr[left].second<arr[right].second){
                return {arr[left].second,arr[right].second};}
                else{return {arr[right].second,arr[left].second};}}

            
            if(sum > target){right--;}
            if(sum<target){left++;}
            // while(arr[left].first==arr[left-1].first){left++;}
            // while(arr[right].first==arr[right+1].first){right--;}
        }
        return {};
    }
};
