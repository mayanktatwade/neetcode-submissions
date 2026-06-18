class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        map<int,int>mp;
        mp[0] = 0;
        mp[1] = 0;
        if(cost.size()==2){return min(cost[0],cost[1]);}

        for(int i =2;i<cost.size();i++){
            mp[i] = min(mp[i-1]+cost[i-1],mp[i-2]+cost[i-2]);
        }
        int size = cost.size();
        int ans = min(mp[size-1]+cost[size-1],mp[size-2]+cost[size-2]);
        return ans;
    }
};
