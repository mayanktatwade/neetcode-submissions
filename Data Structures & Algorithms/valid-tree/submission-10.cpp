class Solution {
public:
bool flag = true;
    void helper(vector<vector<int>>&adj,int node, int last,vector<int>&mp){
        if(mp[node]==1){
            // if(last==node){return;}
            // cout<<last<<" l "<<node<<" n";
            flag = false; return;
        }
        if(adj[node].size()==0){return;}

        mp[node]=1;

        for(int i:adj[node]){
            if(last==i){continue;}
            // cout<<"i: "<<i<<" node: "<<node<<endl;
            helper(adj,i,node,mp);
            if(flag == false){return;}
        }
        // mp[node]=0;
        return;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>mp(n);

        // stack<int>st;

        for(vector<int>v:edges){
            if(v[1]==v[0]){return false;}
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);            
        }
        for(vector v:adj){for(int j:v){cout<<j<<" ";}cout<<endl;}
        vector<int>temp(n); int e = 0;

        for(int i = 0; i<n; i++){
            vector<int>mp(n);
            helper(adj,i,i,mp);
            if(e!=0 && mp != temp){return false;}
            temp = mp;
            if(flag == false){return false;}
            e++;
        }

        return true;
    }
};
