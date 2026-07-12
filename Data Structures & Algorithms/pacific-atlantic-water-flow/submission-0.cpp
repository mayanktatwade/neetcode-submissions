class Solution {
public:
    int m; int n;vector<vector<int>>ans;
    void helper2(vector<vector<int>>& heights,vector<vector<int>>& mp,int x,int y,int val){
        if(x<0 || y<0 ||x>=m || y>=n){return;}
        if(mp[x][y]==2){return;}
        if(heights[x][y]<val){return;}
        mp[x][y]++;
        if(mp[x][y]==2){ans.push_back({x,y});}
        helper2(heights,mp,x+1,y,heights[x][y]);
        helper2(heights,mp,x-1,y,heights[x][y]);
        helper2(heights,mp,x,y+1,heights[x][y]);
        helper2(heights,mp,x,y-1,heights[x][y]);

        return;
    }
    void helper(vector<vector<int>>& heights,vector<vector<int>>& mp,int x,int y,int val){
        if(x<0 || y<0 ||x>=m || y>=n){return;}
        if(mp[x][y]==1){return;}
        if(heights[x][y]<val){return;}
        mp[x][y]=1;
        helper(heights,mp,x+1,y,heights[x][y]);
        helper(heights,mp,x-1,y,heights[x][y]);
        helper(heights,mp,x,y+1,heights[x][y]);
        helper(heights,mp,x,y-1,heights[x][y]);

        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>>mp(m,vector<int>(n));
        vector<vector<int>>mp2(m,vector<int>(n));

        //Pacific
        for(int i = 0; i<m; i++){
            helper(heights,mp,i,0,-1);
        }
        for(int j = 1; j<n; j++){
            helper(heights,mp,0,j,-1);
        }
        // for(int i = 0; i<m ; i++){
        //     for(int j = 0; j<n; j++){
        //         cout<<mp[i][j]<<" ";
        //     }cout<<endl;
        // }
        //Atlantic
        for(int i = 0; i<m; i++){
            helper(heights,mp2,i,n-1,-1);
        }
        for(int j = 0; j<n-1; j++){
            helper(heights,mp2,m-1,j,-1);
        }

        // cout<<endl;
        // for(int i = 0; i<m ; i++){
        //     for(int j = 0; j<n; j++){
        //         cout<<mp2[i][j]<<" ";
        //     }cout<<endl;
        // }
        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n; j++){
                if(mp[i][j] && mp2[i][j]){ans.push_back({i,j});}
            }cout<<endl;
        }
        return ans;
    }
};
