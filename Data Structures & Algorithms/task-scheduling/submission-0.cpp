class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>>pq;

        vector<int>v(26);
        for(char c:tasks){
            v[(int)c-(int)'A']++;
        }
        for(int i = 0; i<26; i++){
            if(v[i]>0){
                pq.push({v[i],i});
            }
        }
        // for(int i:v){
        //     cout<<i<<" ";
        // }cout<<endl;
        // cout<<pq.top().second;
        queue<pair<pair<int,int>,int>>q;

        int idx = 0;
        while(!q.empty() || !pq.empty()){
            if(!q.empty()){
                auto t2 = q.front();
                if(idx - t2.second>n){
                    pq.push(t2.first);
                    q.pop();
                }
            }

            if(!pq.empty()){
            auto temp = pq.top();
            if(temp.first>1){
                q.push({{temp.first-1,temp.second},idx});
                // cout<<temp.second;
            }
            pq.pop();
            }

            idx++;
        }

        return idx;
    }
};
