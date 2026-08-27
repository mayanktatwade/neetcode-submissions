class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i<k;i++){
            pq.push({nums[i],i});
        }
        
        vector<int>ans; pair<int,int>p=pq.top();
        ans.push_back(p.first); 
        if(p.second==0){pq.pop();}

        for(int j = k; j<nums.size(); j++){
            pq.push({nums[j],j});
            bool found = false;
            while(!found){
            p = pq.top();
            if(p.second<=j-k){pq.pop();}
            else{found = true;}
            }
            ans.push_back(p.first);
            // if(p.second<=j-k){pq.pop();}
        }
        return ans;

    }   
};
