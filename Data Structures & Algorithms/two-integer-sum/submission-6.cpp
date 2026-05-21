#include<algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>>arr;
        int j = 0;
        for (int i : nums){
            arr.push_back({i,j++});
        }
        sort(arr.begin(),arr.end());
        int l = 0;
        int r = nums.size()-1;
        int sum;

        while(l<r){
            if(arr[l].first+arr[r].first==target){
                if(arr[l].second<arr[r].second){return {arr[l].second,arr[r].second};}
                else{return {arr[r].second,arr[l].second};}
                }
            else if(arr[l].first+arr[r].first>target){r--;}
            else{l++;}
        }
        return {};
    }
};
