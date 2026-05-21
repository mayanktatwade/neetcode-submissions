class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) return false;
        
        unordered_map<char,int> slist;
        unordered_map<char,int> tlist;

        int size = s.size();
        for(int i = 0; i<size; i++){
            slist[s[i]]++;
            tlist[t[i]]++;   
        }
      
        return slist == tlist;



}
};