class Solution {
public:
int m; int n; int ans=0;
    void helper(queue<vector<int>>& st,vector<vector<int>>& grid){
        if(st.empty()){return;}
        vector<int>arr = st.front();
        int i = arr[0]; int j = arr[1];
        if(arr[0] <0 || arr[0]>=m || arr[1]<0 || arr[1]>=n){st.pop();return;}
        if(grid[arr[0]][arr[1]]==0){st.pop();return;}

        if(grid[i][j]==1){ans = max(ans,arr[2]);}
        grid[arr[0]][arr[1]]=0;
        st.pop();
        st.push({i+1,j,arr[2]+1});
        st.push({i-1,j,arr[2]+1});
        st.push({i,j+1,arr[2]+1});
        st.push({i,j-1,arr[2]+1});

        
        return;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        vector<vector<int>>mp(m,vector<int>(n));
        queue<vector<int>>st;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]!=2){continue;}
                // grid[i][j] = 0;
                st.push({i,j,0});
                
            }
        }
        // cout<<st.size();
        vector<int>arr = st.front();
        // for(int i:arr){cout<<i<<" ";}
        while(!st.empty()){
            helper(st,grid);
            // cout<<st.front()[0]<<" "<<st.front()[1]<<endl;
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]!=0){return -1;}
                cout<<grid[i][j]<<" ";
                
            }cout<<endl;
        }
        return ans;
    }
};
