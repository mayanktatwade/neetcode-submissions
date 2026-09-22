class Solution {
public:
    int n;
    unordered_set<string> st;
    vector<int> dp;

    bool helper(string& s, int idx) {
        if (idx == n) {
            return true;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        string c = "";

        for (int i = idx; i < n; i++) {
            c += s[i];

            if (st.count(c)) {
                if (helper(s, i + 1)) {
                    return dp[idx] = 1;
                }
            }
        }

        return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();

        for (string word : wordDict) {
            st.insert(word);
        }

        dp.assign(n, -1);

        return helper(s, 0);
    }
};
// class Solution {
// public:
// bool ans = false;

// int n;
//     void helper(string s, int idx, set<string>&st, set<int>&mp, string& c){
//         if(idx>=n){
//             if(c.size()==0){ans = true;}
//             return;
//         }

//         if(mp.count(idx)){return;}

//         for(int i = idx; i<n; i++){
//             c.push_back(s[i]);
//             if(st.count(c)){
//                 cout<<c<<endl;
//                 string temp = "";
//                 helper(s,i+1,st,mp,temp);
            
//                 if(ans==false){
//                     cout<<i+1<<endl;
//                     mp.insert(i+1);
//                     continue;
//                 }
//             }

//             if(ans)return;
//         }
//         return;        
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         set<string>st; n = s.size();
//         set<int>mp; string c = "";

//         for(string s:wordDict){
//             st.insert(s);
//         }

//         helper(s,0,st,mp,c);


//         return ans;
//     }
// };
