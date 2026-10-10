class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;                       // stores indices, heights increasing

        for (int i = 0; i <= n; i++) {
            // fake bar of height 0 at the end to flush the stack
            int curr = (i == n) ? 0 : heights[i];

            // current bar is shorter -> finish the taller bars on the stack
            while (!st.empty() && heights[st.top()] >= curr) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, h * width);
            }
            st.push(i);
        }
        return ans;
    }
};
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int idx = 0; int n = heights.size(); 
//         vector<int>dp(n); int ans = 0;
//         int curh=0; int len=0; int area = 0;

//         for(int i = 0; i<n; i++){

//             if(dp[i]){continue;}

//             curh = heights[i];
//             idx = i; len=1;

//             while(idx<n){
//                 curh = min(curh,heights[idx]);
//                 if(curh == heights[idx]){dp[idx]=1;}
//                 if(curh==0){break;}
//                 area = len*curh;
//                 ans = max(area,ans);
//                 len++; idx++;
//             }
//         }

//         return ans;
//     }
// };
