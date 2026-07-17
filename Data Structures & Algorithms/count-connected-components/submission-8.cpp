class Solution {
public:
    void helper(vector<vector<int>>&adj,int node, vector<int>&mp){
        // if(mp[node]==1){return;}
        // if(adj[node].size()==0){return;}

        mp[node]=1;
        for(int i:adj[node]){
            if(!mp[i]){
            helper(adj,i,mp);}
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(vector<int> v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        // for(vector v:adj){for(int j:v){cout<<j<<" ";}cout<<endl;}

        vector<int>mp(n);
        int ans = 0;

        for(int i = 0; i<n; i++){
            if(mp[i]==1){continue;}
            
            helper(adj,i,mp);
            ans++;
        }

        return ans;
    }
};

// class Solution {
// public:
//     void helper(vector<vector<int>>&adj,int node, vector<int>&mp){
//         if(mp[node]==1){return;}
//         if(adj[node].size()==0){return;}

//         mp[node]=1;
//         for(int i:adj[node]){
//             helper(adj,i,mp);
//         }
//         return;
//     }
//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>>adj(n);

//         for(vector<int> v:edges){
//             adj[v[0]].push_back(v[1]);
//             adj[v[1]].push_back(v[0]);
//         }
//         // for(vector v:adj){for(int j:v){cout<<j<<" ";}cout<<endl;}

//         vector<int>check(n);vector<int>ones(n,1);
//         int ans = 0;

//         for(int i = 0; i<n; i++){
//             if(check[i]==1){continue;}
//             vector<int>mp(n);
//             helper(adj,i,mp);
//             ans++;

//             for(int j=0; j<n; j++){
//                 check[j] = max(check[j],mp[j]);
//             }
//         }

//         return ans;
//     }
// };
