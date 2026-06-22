class Solution {
    int start = 0, len = 1;

    void expand(const string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--; r++;
        }
        // after loop, valid palindrome is s[l+1 .. r-1]
        int cur_len = r - l - 1;
        if (cur_len > len) {
            len = cur_len;
            start = l + 1;
        }
    }

public:
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i);     // odd length
            expand(s, i, i + 1); // even length
        }
        return s.substr(start, len);
    }
};
// class Solution {
// public:
//     int len = 0; vector<vector<int>> ans_idx;

//     void helper(string s, int idx){
//         if(idx == s.size()){return;}

//         int left = idx-1; int right = idx+1; int max_len=1;
//         if(left>=0){if(s[left]==s[idx]){max_len++;if(len<max_len){len = max_len; ans_idx.push_back({left++,idx});}}}
//         if(right<s.size()){if(s[right]==s[idx]){max_len++;if(len<max_len){len = max_len; ans_idx.push_back({idx,right++});}}}
//         while(left>=0 && right<s.size()){
//             if(s[left]!=s[right]){break;}
//             if(s[left]==s[right]){max_len+=2;}
            
//             if(len<max_len){
//                 len = max_len; ans_idx.push_back({left,right});
//             }
//             left--;right++;
//             // if(ans_idx.size()!=0){
//             //     cout<<"length: "<<len<<endl;
//             // string temp(
//             //     s.begin() + ans_idx.back()[0],
//             //     s.begin() + ans_idx.back()[1]+1
//             // );
//             // cout<<temp<<endl;
//             // }
//         }
//         helper(s,idx+1);
//         return;
//     }
//     string longestPalindrome(string s) {
//         helper(s,0);
        
//         string temp(
//             s.begin() + ans_idx.back()[0],
//             s.begin() + ans_idx.back()[1]+1
//         );
//         return temp;
//     }
// };
