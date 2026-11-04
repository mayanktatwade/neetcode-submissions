#include <algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n = strs.size();

        int len = 0;
        int minlen = INT_MAX;
        for(int i=0; i<n; i++){
            int temp = strs[i].size();
            minlen  = min(minlen,temp);
        }
        // int len==0;
        // cout<<minlen;
        while(len<minlen){
            char c = strs[0][len]; bool stop = false;
            for(int i=1;i<n;i++){if(c!=strs[i][len]){stop = true;break;}}
            if(stop){break;}
            len++;ans.push_back(c);
        }
        return ans;

    }
};