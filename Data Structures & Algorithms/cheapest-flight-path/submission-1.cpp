class Solution {
public:
int ans = INT_MAX; int k_;
int destination;

    void helper(vector<vector<vector<int>>>& adj, vector<int>&visited, int idx, int cost, int visits){
        if(cost>=ans){return;}
        // if(visited[idx]==1){return;}
        if(idx==destination && visits<=k_){ans = min(cost,ans);}
        if(visits>k_){return;}

        visited[idx] = 1;
        for(int i=0; i<adj[idx].size(); i++){
            // int temp = 
            if(!visited[adj[idx][i][0]]){
            helper(adj,visited,adj[idx][i][0],cost+adj[idx][i][1],visits+1);}
        }
        visited[idx] = 0;
        return;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        destination = dst; k_ = k;
        vector<vector<vector<int>>> adj(n);
        vector<int>visited(n);

        for(auto v:flights){
            adj[v[0]].push_back({v[1],v[2]});
            // adj[v[1]].push_back({v[0],v[2]});
        }
        helper(adj,visited,src,0,-1);
        if(ans == INT_MAX){return -1;}
        return ans;
    }
};
