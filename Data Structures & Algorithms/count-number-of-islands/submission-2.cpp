class Solution {
public:
int ans = 0;
    void helper(vector<vector<char>>& grid,int x,int y){
        if(x>=grid.size() || x<0 || y>=grid[0].size() || y<0){return;}
        if(grid[x][y]=='0'){return;}
        grid[x][y] = '0';
        helper(grid,x+1,y);
        helper(grid,x-1,y);
        helper(grid,x,y+1);
        helper(grid,x,y-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                
                if(grid[i][j]=='0'){
                    continue;
                }
                helper(grid,i,j);
                ans++;

            }
        }
        return ans;
    }
};
