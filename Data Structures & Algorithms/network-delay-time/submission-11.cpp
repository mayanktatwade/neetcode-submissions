class Solution {
public:
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
int ans = -1;
    // void helper(int node, int time, set<int>&mp,vector<vector<pair<int,int>>>adj){
    //     if(mp.count(node)){return;}

        // for(int i=0; i<adj[node].size(); i++){
        //     pair<int,int>p = adj[node][i];
        //     p.first+=time;
        //     pq.push(p);
        // }
    //     return;
    // }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(vector<int>v:times){
            adj[v[0]].push_back({v[2],v[1]});
        }
        set<int>mp; int time = 0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int>p = pq.top();pq.pop();
            if(mp.count(p.second)){continue;}
            mp.insert(p.second);
            ans = max(p.first,ans);

            for(int i=0; i<adj[p.second].size(); i++){
                pair<int,int>r = adj[p.second][i];
                if(mp.count(r.second)){continue;}
                r.first += p.first;
                pq.push(r);
            }
        }
        if(mp.size()<n){return -1;}
        return ans;

    }
};
