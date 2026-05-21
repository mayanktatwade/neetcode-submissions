class Solution {
public:
    vector<int> charmap(string s){
        int size = s.size();
        vector<int> ans(26);
        for(char i: s){
            ans[(int)i-(int)'a']++;
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<vector<int>,int>> main;
        int idx = 0;
        for(string s: strs){
            main.push_back({charmap(s),idx++});
        }

        sort(main.begin(),main.end());

        vector<vector<string>> ans;
        ans.push_back({strs[main[0].second]});
        // int l = 0; int r = 1; 
        int entries = 1;
        for(int i = 1 ; i<main.size();i++){
            if(main[i].first==main[i-1].first){ans[entries-1].push_back(strs[main[i].second]);}
            else{ans.push_back({strs[main[i].second]}); entries++;}
        }

        return ans;
    }
};
