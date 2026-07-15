class Solution {
public:
    double myPow(double x, int n) {
        double temp = x;
        if(n==0){return 1;}
        if(n<0){x = 1/x; temp = x;n=-1*n;}
        if(n==1){return x;}
        
        for(int i = 2; i<=n; i++){
        cout<<x<<" ";
            x = x*temp;
        }

        return x;

    }
};
