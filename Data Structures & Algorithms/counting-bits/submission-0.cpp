class Solution {
public:
    int helper(int n){
        int ones = 0;

        while(n){
            if(n%2==1){ones++;}
            n/=2;
        }
        return ones;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i =0; i<=n; i++){
            ans.push_back(helper(i));
        }
        return ans;
    }
};
