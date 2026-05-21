class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> arr;
        unordered_map<int,int> mp;

        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto &p:mp){
            arr.push_back({p.second,p.first});
        }
        sort(arr.begin(),arr.end());

        vector<int>result;
        int size = arr.size();
        for(int i = 0 ; i<k; i++){
            result.push_back(arr[size-1-i].second);
        }
        return result;
    }
};
