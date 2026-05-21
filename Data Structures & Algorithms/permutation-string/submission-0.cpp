class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1;
        for(auto s:s1){
            mp1[s]++;
        }
        
        map<char,int>mp2;
        for(int i=0; i<s2.size()-s1.size()+1;i++){
            string temp = s2.substr(i,s1.size());
            for(auto s:temp){
                mp2[s]++;
            }
            if(mp1==mp2){return true;}
            mp2.clear();
        }
        return false;
    }
};
