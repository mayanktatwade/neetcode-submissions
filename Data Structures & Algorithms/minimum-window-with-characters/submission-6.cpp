class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        int m = s.size(); int n = t.size();
        vector<int> mp(128, 0);
        vector<bool> needed(128, false);
        for(char c:t){
            mp[c]++;
            needed[c] = true;
        }
        int counter = n;

        int idx = 0;
        int left = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;

        while(idx < m){
            if(needed[(unsigned char)s[idx]]){
                mp[s[idx]]--;
                if(mp[s[idx]] >= 0) counter--;
            }

            while(counter == 0){
                if(idx - left + 1 < bestLen){
                    bestLen = idx - left + 1;
                    bestStart = left;
                }
                if(needed[(unsigned char)s[left]]){
                    mp[s[left]]++;
                    if(mp[s[left]] > 0) counter++;
                }
                left++;
            }
            idx++;
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(t.empty()) return "";

//         int m = s.size(); int n = t.size();
//         string temp; string ans; map<char,int>mp;
//         bool ansfirst = false;
//         for(char c:t){
//             mp[c]++;
//         }
//         int counter = n;

//         // int idx = -1;
//         // for(char c:s){
//         //     idx++;
//         //     if(mp.count(c)){break;}
//         // }
//         // // cout<<idx;
//         int idx = 0;
//         int left = 0;
//         // int idx = 0;

//         vector<int>from_t; //int left=idx; int idx = idx;
//         while(idx < m){
//             if(mp.count(s[idx])){
//                 mp[s[idx]]--;
//                 if(mp[s[idx]] >= 0) counter--;   // only count it if it was still needed
//             }

//             while(counter == 0){
//                 if(!ansfirst || ans.size() > (size_t)(idx-left+1)){
//                     ans = s.substr(left, idx-left+1);
//                     ansfirst = true;
//                 }
//                 if(mp.count(s[left])){
//                     mp[s[left]]++;
//                     if(mp[s[left]] > 0) counter++;
//                 }
//                 left++;
//             }
//             idx++; 
//         }

//         return ans;
//         // return "";


//     }
// };
