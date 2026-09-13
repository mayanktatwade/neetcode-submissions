class Solution {
public:
unordered_set<int>rings;
    void helper(vector<vector<int>>&adj, int idx, int last,map<int,int>&mp, vector<int>&visit){
        // cout<<idx<<" ";
        // for(int i:visit){cout<<i<<" ";}cout<<endl;
        if(mp.count(idx)){
            rings.insert(idx); //cout<<idx<<"idx ";
            for(int i = visit.size()-2; i>=0; i--){
                if(visit[i]==idx){break;}
                rings.insert(visit[i]);//cout<<visit[i]<<" ";
            }
            return;
        }
        mp[idx]++;
        for(int i:adj[idx]){
            if(i==last){continue;}
            visit.push_back(i);
            helper(adj,i,idx,mp,visit);
            visit.pop_back();
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int maxele = 0;
        for(vector<int>v:edges){
            maxele = max(v[0],maxele);
            maxele = max(v[1],maxele);
        }
        vector<vector<int>>adj(maxele+1);
        for(vector<int>v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        // for(vector<int>v:adj){for(int i:v){cout<<i<<" ";}cout<<endl;}

        map<int,int>mp; vector<int>visit;

        visit.push_back(edges[0][0]);
        helper(adj,edges[0][0],0,mp,visit);
        visit.pop_back();

        // for(int x : rings) {
        //     cout << x << " ";
        // }   
        vector<int>ans = edges[0];

        for(int i = edges.size()-1;i>=0;i--){
            auto t = edges[i];
            if(rings.count(t[0]) && rings.count(t[1])){
                ans=t;break;
            }
        }

        return ans;
    }
};
