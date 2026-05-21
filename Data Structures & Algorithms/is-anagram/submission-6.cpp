class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> A;
        unordered_map<char,int> B;
        if(s.size()!=t.size()){return false;}

        for(int i=0;i<s.size();i++){
            A[s[i]]++;
            B[t[i]]++;
        }
        
        if( A==B){return true;}
        else{return false;}
    }
};
