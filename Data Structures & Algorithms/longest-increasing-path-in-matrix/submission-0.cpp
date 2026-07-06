class Solution {
public:
    int ans = -1;
    int maximum(int a,int b,int c, int d){
        return max(max(a,b),max(c,d));
    }
    int helper(vector<vector<int>>& matrix,vector<vector<int>>& dp, int x, int y , int lastele){
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size()){return 0;}

        if(matrix[x][y]>lastele){
            if(dp[x][y]!=-1){return dp[x][y];}
            // dp[x][y] = max(dp[x-1][y],dp[x+1][y],dp[x][y-1],dp[x][y+1])+1;
            dp[x][y] = maximum(
                helper(matrix,dp,x-1,y,matrix[x][y]),
                helper(matrix,dp,x+1,y,matrix[x][y]),
                helper(matrix,dp,x,y-1,matrix[x][y]),
                helper(matrix,dp,x,y+1,matrix[x][y])
            )+1;
            ans = max(ans,dp[x][y]);
            cout<<"x: "<<x<<" y: "<<y<<" ele: "<<dp[x][y]<<endl;
            return dp[x][y];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(dp[i][j]==-1){
                    helper(matrix,dp,i,j,-1);
                }
            }
        }
        
        return ans;
    }
};
