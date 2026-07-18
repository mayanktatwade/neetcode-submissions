class Solution {
public:
    int hammingWeight(uint32_t n) {
        int m = (int)n;
        // cout<<m;
        int ans = 0;

        while(true){
            
            cout<<m<<" ";
            if(m%2==1){ans++;}
            m/=2;

            if(m<=0){break;}
        }


        
        return ans;
    }
};
