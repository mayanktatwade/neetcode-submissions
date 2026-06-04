class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans(temp.size());
        stack<int>st;stack<int>idxst;

        st.push(temp[0]);idxst.push(0);
        int i = 1;

        while(i<temp.size()){
            if(temp[i]>st.top()){
                while(!st.empty()){
                    if(temp[i]>st.top()){
                    ans[idxst.top()] = i-idxst.top();
                    st.pop();idxst.pop();}
                    else{break;}
                }
            }
            st.push(temp[i]);idxst.push(i);
            i++;
        }
        return ans;
    }
};
