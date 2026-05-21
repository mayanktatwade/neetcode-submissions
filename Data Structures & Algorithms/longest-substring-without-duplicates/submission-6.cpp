
class Solution {
public:
    int max(int a,int b){
        if(a<b){return b;}
        return a;
    }
    int lengthOfLongestSubstring(string s) {

        map<char,int>mp;int maxlength = 0;

        int l = 0;
        for(int r=0; r<s.size(); r++){
            char ch = s[r];

            if(mp.count(ch) && mp[ch]>=l){
                l = mp[ch]+1;
            }
            mp[ch] = r;
            maxlength = max(maxlength,r-l+1);
            
        }
        return maxlength;

    }
};
