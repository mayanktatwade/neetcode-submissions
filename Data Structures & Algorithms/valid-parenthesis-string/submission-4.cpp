class Solution {
public:
    bool checkValidString(string s) {
        int min_ = 0;
        int max_ = 0;

        for(char c:s){
            if(c=='('){min_++;max_++;}
            else if(c==')'){min_--;max_--;}
            else{min_--; max_++;}
            min_ = max(0,min_);
            if(max_<0){return false;}
        }
        if(min_ == 0){return true;}

        return false;
    }
};
