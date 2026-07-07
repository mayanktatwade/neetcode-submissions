class Solution {
public:
    int helper(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        if(j==t.size()){return 1;}
        if(j>t.size()||i>=s.size()){return 0;}
        
        if(dp[j][i]!=-1){return dp[j][i];}

        if(s[i]==t[j]){
            dp[j][i] = helper(s,t,i+1,j,dp)+helper(s,t,i+1,j+1,dp);
            return dp[j][i];
        } 
        dp[j][i] = helper(s,t,i+1,j,dp);
        return dp[j][i];
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1<n2){return 0;}
        // map<pair<int,int>,int> mp;
        vector<vector<int>> dp(t.size()+1,vector<int>(s.size()+1,-1));
    
        return helper(s,t,0,0,dp);
    }
};
