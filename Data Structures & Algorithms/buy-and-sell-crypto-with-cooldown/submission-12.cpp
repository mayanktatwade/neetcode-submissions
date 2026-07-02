class Solution {
public:
int ans = 0;
    int helper(vector<int>& prices,int buy_idx,vector<int>& dp){
        if(buy_idx>=prices.size()){return 0;}
        // if(dp[buy_idx]!=-1){return dp[buy_idx]; }
        int temp = 0;

        for(int i = buy_idx+1; i<prices.size(); i++){
            temp = max(temp,prices[i]-prices[buy_idx]+dp[i+2]);
        }
        dp[buy_idx] = max(dp[buy_idx+1],temp);
        cout<<buy_idx<<" profit: "<<dp[buy_idx]<<endl;
        ans = max(ans,temp);

        return temp;
        
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){return 0;}
        int n = prices.size();

        vector<int> dp(n+2,-1);
        dp[n-1] = 0;
        dp[n] = 0; dp[n+1] = 0;

        if(prices[n-1]-prices[n-2]>0){dp[n-2]=prices[n-1]-prices[n-2];}
        if(prices[n-1]-prices[n-2]<=0){dp[n-2]=0;}

        cout<<dp[n-1]<<" "<<dp[n-2]<<endl;
        ans = max(ans,dp[n-2]);
        if(n==2){return dp[n-2];}

        
        for(int i = prices.size()-2; i>=0; i--){
            helper(prices,i,dp);
        }

        return ans;
    }
};
