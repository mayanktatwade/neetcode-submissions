class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        int n = points.size();
        if(n<=1){return 0;}
        vector<int>p1(2); vector<int>p2(2); int dist = 0;

        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                p1 = points[i];
                p2 = points[j];

                dist = abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
                pq.push({dist,i,j});
            }
        }

        stack<vector<int>>st; set<int>mp; int cost = 0;
        vector<int>temp = pq.top(); bool found = false;
        cost += temp[0];
        mp.insert(temp[1]);
        mp.insert(temp[2]);
        // cout<<temp[1]<<" "<<temp[2]<<endl;
        pq.pop();

        while(!pq.empty() || !st.empty()){
            if(found) {while(!st.empty()){pq.push(st.top());st.pop();}}
            temp = pq.top();
            int a = mp.count(temp[1]);
            int b = mp.count(temp[2]);
            // cout<<temp[1]<<" "<<a<<" "<<temp[2]<<" "<<b<<endl;

            if(a&&b){pq.pop(); found = true; continue;}
            if(a||b){
                cost += temp[0];
                mp.insert(temp[1]);
                mp.insert(temp[2]);
                pq.pop();
                found = true;
                continue;
            }

            st.push(temp);
            pq.pop();
            found = false;

        }

        return cost;
    }
};
