class Solution {
public:
    int helper(int l, int r, vector<int>& piles,vector<vector<int>>&dp){
        if(dp[l][r]!=-1){return dp[l][r];}
        if(r-l==1){dp[l][r] = max(piles[l],piles[r]); return dp[l][r];}

        int ans = 0;
        //if choose l
        if(piles[l+1]>piles[r-1]){ans = max(ans,piles[l]+helper(l+2,r,piles,dp));}
        else{ans = max(ans,piles[l]+helper(l+1,r-1,piles,dp));}

        if(piles[l]>piles[r-1]){ans = max(ans,piles[r]+helper(l+1,r-1,piles,dp));}
        else{ans = max(ans,piles[r]+helper(l,r-2,piles,dp));}

        dp[l][r] = ans;
        return dp[l][r];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int total = 0;
        for(int i:piles){total+=i;}

        int alice = helper(0,n-1,piles,dp);

        if(2*alice>total){return true;}
        return false;


    }
};