class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>>v(m+1,vector<int>(n+1));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                v[i][j]=grid[i-1][j-1];
                
                if(i==1){v[i][j]+=v[i][j-1];}
                else if(j==1){v[i][j]+=v[i-1][j];}
                else{v[i][j]+=min(v[i-1][j],v[i][j-1]);}
            }
        }
        return v[m][n];
    }
};