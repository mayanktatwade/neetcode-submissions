class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char i : s) {
            // if(!st.empty()){cout<<st.top()<<" ";}
            if (i == '{' || i == '[' || i == '(') {
                st.push(i);
            } 
            else {
                if (i == '}') {
                    if (!st.empty()) {
                        if (st.top() == '{') {
                            st.pop();
                        }
                        else{st.push(i);}
                    }
                    else{st.push(i);}
                }
                if (i == ']') {
                    if (!st.empty()) {
                        if (st.top() == '[') {
                            st.pop();
                        }
                        else{st.push(i);}
                    }
                    else{st.push(i);}
                }
                if (i == ')') {
                    if (!st.empty()) {
                        if (st.top() == '(') {
                            st.pop();
                        }
                        else{st.push(i);}
                    }
                    else{st.push(i);}
                }
            }
        }
        return st.empty();
    }
};
