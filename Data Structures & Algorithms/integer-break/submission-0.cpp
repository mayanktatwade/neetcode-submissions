class Solution {
public:
    int integerBreak(int n) {
        if(n==2){return 1;} if(n==3){return 2;}
        vector<int>dp(n+1);
        dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;
        

        for(int i=4; i<n+1; i++){
            int temp = 0; int l=i-1; int r = 1;
            cout<<i<<" : ";
            while(r<=l){
                temp = max(temp,dp[l]*dp[r]);
                l--;r++;
                cout<<temp<<" ";
            }cout<<endl;
            dp[i] = temp;
        }
        return dp[n];
    }
};