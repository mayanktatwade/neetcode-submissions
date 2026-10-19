class Solution {
public:
int n;
    bool helper(int rate, vector<int>& piles, int h){
        for(int i = 0; i<n; i++){
            int temp = piles[i]%rate;
            if(temp>0){
                h -= piles[i]/rate+1;
            }
            if(temp==0){h-=piles[i]/rate;}
            if(h<0){return false;}
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxele = 0; n = piles.size();
        for(int i:piles){maxele = max(maxele, i);}

        int l = 1; int r = maxele; int ans = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            if(helper(m,piles,h)){ans = min(ans,m);r = m-1;}
            else{l = m+1;}
        }
        return ans;
    }
};
