class Solution {
public:
bool ans = false;

int n;
    void helper(string s, int idx, set<string>&st, set<int>&mp, string& c){
        if(idx>=n){
            if(c.size()==0){ans = true;}
            return;
        }

        if(mp.count(idx)){return;}

        for(int i = idx; i<n; i++){
            c.push_back(s[i]);
            if(st.count(c)){
                cout<<c<<endl;
                string temp = "";
                helper(s,i+1,st,mp,temp);
            
                if(ans==false){
                    cout<<i+1<<endl;
                    mp.insert(i+1);
                    continue;
                }
            }

            if(ans)return;
        }
        return;        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st; n = s.size();
        set<int>mp; string c = "";

        for(string s:wordDict){
            st.insert(s);
        }

        helper(s,0,st,mp,c);


        return ans;
    }
};
