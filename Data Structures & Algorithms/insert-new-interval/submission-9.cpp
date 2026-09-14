class Solution {
public:
    bool isOverlapping(vector<int>&a, vector<int>&b){
        if(a[1]<b[0]){return false;}
        return true;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){return {newInterval};}

        
        for(int i=0; i<intervals.size();i++){
            if(newInterval[0]<=intervals[i][0]){
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
            if(i==intervals.size()-1){
                intervals.push_back(newInterval);
            }
        }
        
        vector<vector<int>> ans;

        int idx = 1;
        ans.push_back(intervals[0]);

        while(idx < intervals.size()){
        if(isOverlapping(ans.back(), intervals[idx])){
            if(ans.back()[1] < intervals[idx][1]){
                ans.back()[1] = intervals[idx][1];
            }
        }
        else{
            ans.push_back(intervals[idx]);
        }
        idx++;
        }

        return ans;
    }
};
