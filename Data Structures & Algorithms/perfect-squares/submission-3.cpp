class Solution {
public:
int s;
    void helper(vector<int>&v, vector<int>&dp, int n){

        int ans = INT_MAX;
        for(int i=0; i<s;i++){
            if(v[i]>n){break;}
            ans = min(ans,1+dp[n-v[i]]);
        }
        dp[n] = ans;
        return;
    }
    int numSquares(int n) {
        //build a list of perfect sqaures till <=n

        vector<int>v;
        int idx = 1;
        while(idx*idx<=n){
            v.push_back(idx*idx);
            idx++;
        }
        for(int i:v){cout<<i<<" ";}cout<<endl;
        s = v.size();
        if(n==v[s-1]){return 1;}

        vector<int>dp(n+1);

        for(int i=1; i<=n;i++){
            helper(v,dp,i);
        }

        return dp[n];

        
    }
};