class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& x) {
        int m = x.size(); int n=x[0].size();
        vector<vector<int>>dp(m,vector<int>(n));

        for(int i=0; i<n && x[0][i]!=1; i++){dp[0][i]=1;}
        for(int i=1; i<m && x[i][0]!=1; i++){dp[i][0]=1;}

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(x[i][j]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};