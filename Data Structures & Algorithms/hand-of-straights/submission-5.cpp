class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); int maxele = 0;
        for(int i =0; i<n; i++){
            maxele = max(maxele,hand[i]);
        }
        vector<int>v(maxele+1);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<n; i++){
            v[hand[i]]++; pq.push(hand[i]);
        }

        while(!pq.empty()){
            
            int i = pq.top();
            if(v[i]){
                int temp = groupSize;
                int idx = i; int val = v[i];
                while(temp && idx<=maxele){
                    v[idx]-=val;
                    if(v[idx]<0){return false;}
                    idx++;temp--;
                }
                if(temp>0){return false;}
            }
            pq.pop();
        }

        return true;
    }
};
