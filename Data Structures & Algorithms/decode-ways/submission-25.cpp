class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        map<int, int> mp;
        int ans, temp1, temp2;

        for (int i = 0; i < s.size(); i++) {
            temp1 = 1;
            temp2 = 0;

            if (i + 1 < s.size() && s[i + 1] == '0') {
                // Next char is '0', so s[i] and s[i+1] must form 10 or 20
                if (!(s[i] == '1' || s[i] == '2')) return 0;

                temp1 = (i - 1 >= 0) ? mp[i - 1] : 1;
                ans = temp1;
                mp[i] = ans;
                i++;
                mp[i] = ans;

            } else {
                if (s[i] == '0') return 0;

                if (mp.count(i - 1) && mp.count(i - 2)) {
                    temp1 = mp[i - 1];
                    if (i - 1 >= 0 && s[i - 1] != '0') {
                        int two = stoi(s.substr(i - 1, 2));
                        temp2 = (two >= 1 && two <= 26) ? mp[i - 2] : 0;
                    }
                } else {
                    temp1 = 1;
                    if (i - 1 >= 0 && s[i - 1] != '0') {
                        int two = stoi(s.substr(i - 1, 2));
                        temp2 = (two >= 1 && two <= 26) ? 1 : 0;
                    }
                }

                ans = temp1 + temp2;
                mp[i] = ans;
            }
        }

        return mp[s.size() - 1];
    }
};