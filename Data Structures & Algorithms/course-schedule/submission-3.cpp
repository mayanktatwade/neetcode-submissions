class Solution {
public:
    void dfs(vector<int>&arr,int node,vector<vector<int>>&adj,bool & flag){
        if(arr[node]==1){flag = false;return;}
        if(adj[node].size()==0){return;}

        arr[node] = 1;

        for(int i:adj[node]){
            dfs(arr,i,adj,flag);
            if(flag == false){return;}
        }
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        


        for(vector v:prerequisites){
            adj[v[1]].push_back(v[0]);
        }

        // for(vector v:adj){for(int j:v){cout<<j<<" ";}cout<<endl;}

        bool flag = true;
        for(int i = 0; i<numCourses; i++){
            vector<int>arr(numCourses,0);
            dfs(arr,i,adj,flag);
            if(flag == false){return false;}
        }
        return true;

        
    }
};
