// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<
//         pair<float,int>,
//         vector<pair<float,int>>,
//         greater<pair<float,int>>
//         > pq;   

//         int idx = 0; 
//         for(vector<int> i: points){
//             cout<<i[0]<<" "<<i[1]<<endl;
//             float dist = i[0]*i[0]+i[1]*i[1];
//             pq.push({dist,idx++});
//             // if(pq.size()>k){pq.pop();}
//             cout<<dist<<endl;
//         }
        
//         vector<vector<int>>ans;
//         while(k--){
//             ans.push_back(points[pq.top().second]);
//             pq.pop();
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;

            pq.push({dist, i});

            if(pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};