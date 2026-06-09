class Solution {

public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){return stones[0];}
        if(stones.size()==2){return max(stones[0],stones[1])-min(stones[0],stones[1]);}
        priority_queue<int> pq;

        for(int i:stones){
            pq.push(i);
        }
        int a, b;
        while(pq.size()>1){
            a = pq.top();pq.pop();
            b = pq.top();pq.pop();
            cout<<a<<" "<<b<<endl;

            if(a!=b){
                pq.push(a-b);
            }
        }
        if(pq.size()==1){
        return pq.top();}
        return 0;
    }
};
