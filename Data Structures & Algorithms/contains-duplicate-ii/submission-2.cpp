class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        // cout<<b<<a<<b-a+1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(mp.count(nums[i])){
                if(abs(i-mp[nums[i]])<=k){return true;}
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};