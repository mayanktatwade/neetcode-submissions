class Solution {
public:
    int target; int ans;map<int,int>mp;

    int climbStairs(int n) {
        if(n==1){return 1;}
        if(n==2){return 2;}
        mp[1]=1;
        mp[2]=2;
        for(int i=3; i<n ;i++){
            mp[i]= mp[i-1]+mp[i-2];
        }
        return mp[n-1]+mp[n-2];
    }
};
