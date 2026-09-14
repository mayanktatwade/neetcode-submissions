class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;

        for (auto& interval : intervals) {

            // Current interval is completely BEFORE newInterval
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            }

            // Current interval is completely AFTER newInterval
            else if (interval[0] > newInterval[1]) {
                result.push_back(newInterval);
                newInterval = interval;
            }

            // They overlap
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        // If it hasn't been inserted yet
        result.push_back(newInterval);
        return result;
    }
};
// class Solution {
// public:
//     bool isOverlapping(vector<int>&a, vector<int>&b){
//         if(a[1]<b[0]){return false;}
//         return true;
//     }
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         if(intervals.size()==0){return {newInterval};}

//         for(int i=0; i<intervals.size();i++){
//             if(newInterval[0]<=intervals[i][0]){
//                 intervals.insert(intervals.begin()+i,newInterval);
//                 break;
//             }
//             if(i==intervals.size()-1){
//                 intervals.push_back(newInterval);
//             }
//         }
        
//         vector<vector<int>> ans;

//         int idx = 1;
//         ans.push_back(intervals[0]);

//         while(idx < intervals.size()){
//         if(isOverlapping(ans.back(), intervals[idx])){
//             if(ans.back()[1] < intervals[idx][1]){
//                 ans.back()[1] = intervals[idx][1];
//             }
//         }
//         else{
//             ans.push_back(intervals[idx]);
//         }
//         idx++;
//         }

//         return ans;
//     }
// };
