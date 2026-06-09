class KthLargest {
private:
priority_queue<int, vector<int>, greater<int>> pq;
int kk;
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k){pq.pop();}
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kk){pq.pop();}
        return pq.top();
    }
};
