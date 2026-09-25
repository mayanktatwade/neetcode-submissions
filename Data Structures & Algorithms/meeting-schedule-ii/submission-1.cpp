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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0){return 0;}
        if(n==1){return 1;}
        vector<vector<int>>inter(n);
        int maxtime = 0;

        for(int i =0; i<n; i++){
            inter[i].push_back(intervals[i].start);
            inter[i].push_back(intervals[i].end);
            maxtime = max(maxtime,inter[i][0]);
            maxtime = max(maxtime,inter[i][1]);
        }
        sort(inter.begin(),inter.end());

        int rooms = 0; int ans = 0;
        vector<int>meetend(maxtime+1);
        vector<int>meetstart(maxtime+1);

        for(int i=0; i<n; i++){
            meetstart[inter[i][0]]++;
            meetend[inter[i][1]]++;
        }

        for(int i=inter[0][0]; i<maxtime+1; i++){
            if(meetstart[i]){
                rooms+=meetstart[i];
            }
            if(meetend[i]){
                rooms-=meetend[i];
            }
            ans = max(ans,rooms);
        }
        return ans;
    }
};
