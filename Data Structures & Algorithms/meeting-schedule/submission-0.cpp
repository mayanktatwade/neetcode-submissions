/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<vector<int>>inter(n);

        for(int i =0; i<n; i++){
            inter[i].push_back(intervals[i].start);
            inter[i].push_back(intervals[i].end);
        }
        sort(inter.begin(),inter.end());


        for(int i = 1; i<n; i++){
            if(inter[i][0]<inter[i-1][1]){return false;}
            inter[i][1] = max(inter[i][1],inter[i-1][1]);
        }
        return true;
    }
};
