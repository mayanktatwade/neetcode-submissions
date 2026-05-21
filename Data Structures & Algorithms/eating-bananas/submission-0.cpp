class Solution {
public:
    int gethours(vector<int>& piles,int k){
        int res =0; 
        for(auto p:piles){
            if(p%k==0){res += p/k;}
            else{res += p/k + 1;}
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max1 = -1;
        for(auto p:piles){
            max1 = max(max1,p);
        }
        int l =1; int r = max1;
        int ans;


        while(l<=r){
            int mid = (l+r)/2;
            cout<<"mid :"<<mid<<endl;

            if(gethours(piles,mid)<=h){
                ans = mid;
                
                r = mid-1;
                cout<<"ans :"<<ans<<endl;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
