class Solution {
public:
map<int,int>mp;
    bool isHappy(int n) {
        if(mp.count(n)){return false;}

        mp[n]++;
        int temp = n;int sum = 0;
        while(temp>0){
            // cout<<temp%10<<" ";
            sum = (temp%10) * (temp%10) + sum;
            // cout<<sum<<endl;
            temp /= 10;
        }cout<<endl;
        cout<<sum<<endl;
        if(sum == 1){return true;}

        
        return isHappy(sum); 
    }
};
