class Solution {
public:
map<int,int> mp;

int helper(string& s, int idx) {
    if (idx == -1 || idx == -2) return 1;   // valid decode
    if (mp.count(idx)) return mp[idx];

    if (s[idx] == '0') {
        // '0' must be part of 10 or 20
        if (idx - 1 >= 0 && (s[idx-1] == '1' || s[idx-1] == '2')) {
            return mp[idx] = helper(s, idx - 2);
        }
        return mp[idx] = 0;  // invalid
    }

    int ways = helper(s, idx - 1);  // take single char

    if (idx - 1 >= 0) {
        int temp = stoi(s.substr(idx - 1, 2));
        if (temp >= 10 && temp <= 26) {   // note: 10, not 0
            ways += helper(s, idx - 2);  // take two chars
        }
    }

    return mp[idx] = ways;
}

int numDecodings(string s) {
    mp.clear();
    return helper(s, s.size() - 1);
}
};
