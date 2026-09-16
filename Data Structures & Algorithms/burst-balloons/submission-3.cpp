class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n+2);
        a[0] = 1; a[n+1] = 1;
        for(int i=0;i<n;i++) a[i+1] = nums[i];

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int len = 2; len <= n+1; len++){
            for(int l = 0; l+len <= n+1; l++){
                int r = l+len;
                for(int k = l+1; k < r; k++){
                    int val = dp[l][k] + dp[k][r] + a[l]*a[k]*a[r];
                    dp[l][r] = max(dp[l][r], val);
                }
            }
        }

        return dp[0][n+1];
    }
};
// class Solution {
// public:
// int ans = 0;
// int n;
//     void helper(vector<int>& nums,vector<int>&left, vector<int>&right, 
//         map<vector<int>,int>&mp,vector<int>&burst, int prod, int idx){
//         if(mp.count(burst)){
//             if(mp[burst]>prod){return;}
//         }

//         burst[idx] = 1;
//         int l = nums[left[idx]]; int r = nums[right[idx]];
//         if(left[idx]==0){l = 1;} if(right[idx] == n-1){r = 1;}
//         int temp = prod + l*r*nums[idx];

//         ans = max(ans,temp);
//         mp[burst] = temp;

//         int l_r = 0; int r_l = n-1;
//         if(idx==0){l_r = left[right[0]];left[right[0]]=0;}
//         else if(idx==n-1){r_l = right[left[n-1]];right[left[n-1]]=n-1;}
//         else{
//             l_r = left[right[idx]];
//             r_l = right[left[idx]];
//             left[right[idx]] = left[idx];
//             right[left[idx]] = right[idx];
//         }
//         cout<<"left ";for(int i:left){cout<<i<<" ";}//cout<<endl;
//         cout<<"right ";for(int i:right){cout<<i<<" ";}//cout<<endl;
//         cout<<"burst ";for(int i:burst){cout<<i<<" ";}cout<<endl;

//         for(int i = 0; i<n; i++){
//             if(burst[i]!=1){
//                 helper(nums,left,right,mp,burst,temp,i);
//             }
//         }

//         burst[idx] = 0;
//         if(idx==0){left[right[0]] = l_r;}
//         else if(idx==n-1){right[left[n-1]]=r_l;}
//         else{
//             left[right[idx]] = l_r;
//             right[left[idx]] = r_l;
//         }

//         return;


//     }
//     int maxCoins(vector<int>& nums) {
        
//         n = nums.size();
//         vector<int>left(n,1);
//         vector<int>right(n,1);
//         vector<int>burst(n,0);


//         for(int i=1;i<n-1;i++){
//             left[i] = i-1;
//             right[i] = i+1;
//         }
//         right[0] = 1; left[0] = 0;
//         left[n-1] = n-2; right[n-1] = 0;

//         map<vector<int>,int>mp;

//         cout<<"left ";for(int i:left){cout<<i<<" ";}cout<<endl;
//         cout<<"right ";for(int i:right){cout<<i<<" ";}cout<<endl;
//         cout<<"burst ";for(int i:burst){cout<<i<<" ";}cout<<endl;

//         for(int i = 0; i<n; i++){
//             vector<int>leftc = left;
//             vector<int>rightc = right;
//             vector<int>burstc = burst;
//             helper(nums,leftc,rightc,mp,burstc,0,i);
//         }

//         return ans;

//     }
// };
