class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if(n<=0){return 0;}

        int ans = 0;

        for(int i=1; i<n; i++){
            if(intervals[i][0]<intervals[i-1][1]){
                if(intervals[i][1]>intervals[i-1][1]){
                    intervals[i] = intervals[i-1];
                }
                ans++;
            }
        }
        return ans;
    }
};
