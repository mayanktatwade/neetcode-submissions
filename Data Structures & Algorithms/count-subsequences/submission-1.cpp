class Solution {
public:
    int helper(string& s, string& t, int i, int j, map<pair<int,int>,int>& mp){
        if(j==t.size()){return 1;}
        if(j>t.size()||i>=s.size()){return 0;}
        
        if(mp.count({j,i})){return mp[{j,i}];}

        if(s[i]==t[j]){
            mp[{j,i}] = helper(s,t,i+1,j,mp)+helper(s,t,i+1,j+1,mp);
            return mp[{j,i}];
        } 
        mp[{j,i}] = helper(s,t,i+1,j,mp);
        return mp[{j,i}];
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1<n2){return 0;}
        map<pair<int,int>,int> mp;
    
        helper(s,t,0,0,mp);
        return helper(s,t,0,0,mp);
    }
};
