// class Solution {
// public:
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
        
//     }
// };
class Solution {
public:
int area = 0; int n; int m;
    int helper(vector<vector<int>>& grid,int x,int y){
        if(x>=n || x<0 || y>=m || y<0){return 0;}
        if(grid[x][y]==0){return 0;}
        grid[x][y] = 0;
        return 1+
        helper(grid,x+1,y)+
        helper(grid,x-1,y)+
        helper(grid,x,y+1)+
        helper(grid,x,y-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();m=grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                
                if(grid[i][j]==0){
                    continue;
                }
                int temp = helper(grid,i,j);
                area = max(area,temp);

            }
        }
        return area;
    }
};
