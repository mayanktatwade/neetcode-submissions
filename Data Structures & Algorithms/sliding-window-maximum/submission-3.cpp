class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            // Remove elements outside current window
            while(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Window is ready
            if(i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         priority_queue<pair<int,int>> pq;
//         for(int i = 0; i<k;i++){
//             pq.push({nums[i],i});
//         }
        
//         vector<int>ans; pair<int,int>p=pq.top();
//         ans.push_back(p.first); 
//         if(p.second==0){pq.pop();}

//         for(int j = k; j<nums.size(); j++){
//             pq.push({nums[j],j});
//             bool found = false;
//             while(!found){
//             p = pq.top();
//             if(p.second<=j-k){pq.pop();}
//             else{found = true;}
//             }
//             ans.push_back(p.first);
//             // if(p.second<=j-k){pq.pop();}
//         }
//         return ans;

//     }   
// };
