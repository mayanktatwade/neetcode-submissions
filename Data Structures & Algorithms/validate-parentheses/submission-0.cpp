#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracket = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // If opening bracket, push it
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // If closing bracket
            else {
                if (st.empty() || st.top() != bracket[c]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
