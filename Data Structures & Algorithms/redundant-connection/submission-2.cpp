// class Solution {
// public:
// map<int,unordered_set<int>>rings;
// int ring = 0;
//     void helper(vector<vector<int>>&adj, int idx, int last,map<int,int>&mp, vector<int>&visit){
//         // cout<<idx<<" ";
//         // for(int i:visit){cout<<i<<" ";}cout<<endl;
//         if(mp.count(idx)){
//             rings[idx].insert(ring); //cout<<idx<<"idx ";
//             for(int i = visit.size()-2; i>=0; i--){
//                 if(visit[i]==idx){break;}
//                 rings[visit[i]].insert(ring);//cout<<visit[i]<<" ";
//             }
//             ring++;
//             return;
//         }
//         mp[idx]++;
//         for(int i:adj[idx]){
//             if(i==last){continue;}
//             visit.push_back(i);
//             helper(adj,i,idx,mp,visit);
//             visit.pop_back();
//         }
//         return;
//     }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
//         int maxele = 0;
//         for(vector<int>v:edges){
//             maxele = max(v[0],maxele);
//             maxele = max(v[1],maxele);
//         }
//         vector<vector<int>>adj(maxele+1);
//         for(vector<int>v:edges){
//             adj[v[0]].push_back(v[1]);
//             adj[v[1]].push_back(v[0]);
//         }

//         // for(vector<int>v:adj){for(int i:v){cout<<i<<" ";}cout<<endl;}

//         map<int,int>mp; vector<int>visit;

//         visit.push_back(edges[0][0]);
//         helper(adj,edges[0][0],0,mp,visit);
//         visit.pop_back();

//         // for(int x : rings) {
//         //     cout << x << " ";
//         // }   
//         vector<int>ans = edges[0];

//         for(int i = edges.size()-1;i>=0;i--){
//             auto t = edges[i];
//             if(rings.count(t[0]) && rings.count(t[1])){
//                 for(int x:rings[t[0]]){
//                     if(rings[t[1]].count(x)){
//                         ans=t;break;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    unordered_set<int> rings;
    vector<int> onStack; // 0/1, size maxele+1

    bool helper(vector<vector<int>>&adj, int idx, int last, vector<int>&visited, vector<int>&visit){
        visited[idx] = 1;
        onStack[idx] = 1;
        visit.push_back(idx);

        for(int nxt : adj[idx]){
            if(nxt == last) continue;
            if(onStack[nxt]){ // true back edge to an ancestor -> real cycle
                for(int i = visit.size()-1; i>=0; i--){
                    rings.insert(visit[i]);
                    if(visit[i]==nxt) break;
                }
                onStack[idx] = 0; visit.pop_back();
                return true;
            }
            if(!visited[nxt]){
                if(helper(adj,nxt,idx,visited,visit)) {
                    onStack[idx]=0; visit.pop_back();
                    return true; // one cycle exists total, stop searching
                }
            }
            // if visited but not onStack -> already-explored, non-ancestor node: skip, not a cycle
        }
        onStack[idx] = 0;
        visit.pop_back();
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int maxele = 0;
        for(auto&v:edges) maxele = max({maxele, v[0], v[1]});
        vector<vector<int>> adj(maxele+1);
        for(auto&v:edges){ adj[v[0]].push_back(v[1]); adj[v[1]].push_back(v[0]); }

        vector<int> visited(maxele+1,0), visit;
        onStack.assign(maxele+1,0);
        helper(adj, edges[0][0], -1, visited, visit);

        for(int i=edges.size()-1;i>=0;i--)
            if(rings.count(edges[i][0]) && rings.count(edges[i][1]))
                return edges[i];
        return edges[0];
    }
};