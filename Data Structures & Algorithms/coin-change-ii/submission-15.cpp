class Solution {
public:
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}
    int change1(int amount, vector<int>& coins) {
        if(amount == 0){return 1;}
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()));
        sort(coins.begin(), coins.end());

        for(int i=0; i<coins.size(); i++){
            dp[coins[i]][i]=1;
        }
        int temp;
        for(int i=0; i<=amount; i++){
            temp = 0;
            for(int j =0; j<coins.size(); j++){
                if(coins[j]>i){dp[i][j]+=temp;continue;}
                
                dp[i][j] += dp[i-coins[j]][j]+temp;
                temp = dp[i][j];
            }
        }
        
        return dp[amount][coins.size()-1];
    }
};
