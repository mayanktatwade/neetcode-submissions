class Solution {
public:
int ans=0;
    void helper(string s,int l, int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            ans++;l--;r++;
        }
        return;

    }
    int countSubstrings(string s) {
        for(int i=0; i<s.size(); i++){
            helper(s,i,i);
            helper(s,i,i+1);
        }
        return ans;
    }
};
