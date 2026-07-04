class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0){return 1;}
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()));
        sort(coins.begin(), coins.end());

        for(int i=0; i<coins.size(); i++){
            dp[coins[i]][i]=1;
            // cout<<dp[coins[i]][i]<<" ";
        }
        int temp;
        for(int i=0; i<=amount; i++){
            temp = 0;
            for(int j =0; j<coins.size(); j++){
                if(coins[j]>i){dp[i][j]+=temp;continue;}
                
                dp[i][j] += dp[i-coins[j]][j]+temp;
                temp = dp[i][j];
            }
            // for(int k =0; k<coins.size(); k++){
            //     cout<<dp[i][k]<<" ";
            // }cout<<endl;
        }
        
        return dp[amount][coins.size()-1];
    }
};
