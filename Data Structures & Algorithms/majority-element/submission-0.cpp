class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int i:nums){
            
            mp[i]++;
            if(mp.count(i)&&mp[i]>n/2){return i;}
        }
        return 0;
    }
};