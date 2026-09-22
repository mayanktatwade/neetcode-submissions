class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        if(n<=1){return intervals;}

        int s = intervals[0][0]; int e = intervals[0][1];

        for(int i=1; i<n; i++){
            if(intervals[i][0]<=e){
                e = max(intervals[i][1],e);
                continue;
            }
            ans.push_back({s,e});
            s = intervals[i][0];
            e = intervals[i][1];
        }
        ans.push_back({s,e});
        return ans;
    }
};
