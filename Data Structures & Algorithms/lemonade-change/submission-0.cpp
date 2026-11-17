class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0; int five = 0; int n = bills.size();

        for(int i=0; i<n; i++){
            if(bills[i]==5){five++;}
            else if(bills[i]==10){ten++; five--;}
            else{
                if(ten>0){ten--;five--;}
                else{five-=3;}
            }
            if(ten<0 || five<0){return false;}
        }
        return true;
    }
};