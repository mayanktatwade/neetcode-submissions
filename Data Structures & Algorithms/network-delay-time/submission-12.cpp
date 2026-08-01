class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1); // adj[u] = {v, weight}
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<bool> visited(n + 1, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k});

        int ans = -1, count = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();
            if (visited[node]) continue;

            visited[node] = true;
            ans = time;      // heap guarantees non-decreasing pop order
            count++;
            if (count == n) break;   // all nodes reached, stop early

            for (auto& [nei, w] : adj[node]) {
                if (!visited[nei]) {
                    pq.push({time + w, nei});
                }
            }
        }

        return count == n ? ans : -1;
    }
};

// class Solution {
// public:
// priority_queue<
//     pair<int,int>,
//     vector<pair<int,int>>,
//     greater<pair<int,int>>
// > pq;
// int ans = -1;

//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
//         vector<vector<pair<int,int>>>adj(n+1);
        
//         for(vector<int>v:times){
//             adj[v[0]].push_back({v[2],v[1]});
//         }
//         set<int>mp; int time = 0;
//         pq.push({0,k});
//         while(!pq.empty()){
//             pair<int,int>p = pq.top();pq.pop();
//             if(mp.count(p.second)){continue;}
//             mp.insert(p.second);
//             ans = max(p.first,ans);

//             for(int i=0; i<adj[p.second].size(); i++){
//                 pair<int,int>r = adj[p.second][i];
//                 if(mp.count(r.second)){continue;}
//                 r.first += p.first;
//                 pq.push(r);
//             }
//         }
//         if(mp.size()<n){return -1;}
//         return ans;

//     }
// };
