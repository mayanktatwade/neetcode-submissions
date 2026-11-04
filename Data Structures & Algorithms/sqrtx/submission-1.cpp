class Solution {
public:
    int mySqrt(int x) {
        int l=0; int r = x;
        int mid;
        while(l<r){
            mid = (l+r+1)/2;
            cout<<mid<<" ";
            if(1LL*mid*mid==x){return mid;}
            else if(1LL*mid*mid>x){r= mid-1;}
            else{l=mid;}
        }
        return (l+r+1)/2;
    }
};