// class Solution {
// public:
//     void dfs(vector<int>&arr,int node,vector<vector<int>>&adj,bool & flag){
//         if(arr[node]==1){flag = false;return;}
//         if(adj[node].size()==0){return;}

//         arr[node] = 1;

//         for(int i:adj[node]){
//             dfs(arr,i,adj,flag);
//             if(flag == false){return;}
//         }
//         return;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>>adj(numCourses);
        
//         for(vector v:prerequisites){
//             adj[v[1]].push_back(v[0]);
//         }

//         // for(vector v:adj){for(int j:v){cout<<j<<" ";}cout<<endl;}

//         bool flag = true;
//         for(int i = 0; i<numCourses; i++){
//             vector<int>arr(numCourses,0);
//             dfs(arr,i,adj,flag);
//             if(flag == false){return false;}
//         }
//         return true;

        
//     }
// };

class Solution {
public:

    bool flag = true;
    void helper(vector<vector<int>>&adj,int node,stack<int>&st, set<int>&mp, vector<int>&dp){
        
        if(mp.count(node)){flag = false; return;}
        if(adj[node].size()==0){return;}

        if(dp[node] == 1){return;}

        st.push(node); mp.insert(node);
        // cout<<st.top()<<" ";
        
        for(int i:adj[node]){
            helper(adj,i,st,mp,dp);
            if(flag == false){return;}
        }
        st.pop();mp.erase(node);
        dp[node] = 1;
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>dp(numCourses);
    
        for(vector v:prerequisites){
            adj[v[1]].push_back(v[0]);
        } 
        // for(vector v:adj){for(int j:v){cout<<j<<" ";}cout<<endl;}


        stack<int>st; set<int>mp;
        for(int i = 0; i<numCourses; i++){
            // st.push(i);mp[i]++;
            helper(adj,i,st,mp,dp);
            if(flag==false){return false;}
        }
        return true;

    }
};
