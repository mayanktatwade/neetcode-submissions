class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int idx = 0; int n = heights.size(); 
        vector<int>dp(n); int ans = 0;
        int curh=0; int len=0; int area = 0;

        for(int i = 0; i<n; i++){

            if(dp[i]){continue;}

            curh = heights[i];
            idx = i; len=1;

            while(idx<n){
                curh = min(curh,heights[idx]);
                if(curh == heights[idx]){dp[idx]=1;}
                if(curh==0){break;}
                area = len*curh;
                ans = max(area,ans);
                len++; idx++;
            }
        }

        return ans;
    }
};
