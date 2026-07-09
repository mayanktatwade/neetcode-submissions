// class Solution {
// public:
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
        
//     }
// };
class Solution {
public:
int area = 0;
    int helper(vector<vector<int>>& grid,int x,int y){
        if(x>=grid.size() || x<0 || y>=grid[0].size() || y<0){return 0;}
        if(grid[x][y]==0){return 0;}
        grid[x][y] = 0;
        int ans = 1+
        helper(grid,x+1,y)+
        helper(grid,x-1,y)+
        helper(grid,x,y+1)+
        helper(grid,x,y-1);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                
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
