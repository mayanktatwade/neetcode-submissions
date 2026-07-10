class Solution {
public:
    int m; int n;
    void helper(vector<vector<int>>& grid,int x, int y,int dist){
        if(x<0 || y<0 || x>=m || y>=n){return;};
        if(grid[x][y]==-1 ){return;}

        if(grid[x][y]!=0){
            if(grid[x][y]<dist){return;}
            grid[x][y] = dist;
        }

        helper(grid,x+1,y,dist+1);
        helper(grid,x-1,y,dist+1);
        helper(grid,x,y+1,dist+1);
        helper(grid,x,y-1,dist+1);

        return;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]!=0){
                    continue;
                }
                helper(grid,i,j,0);
            }
        }
        return;
    }
};
