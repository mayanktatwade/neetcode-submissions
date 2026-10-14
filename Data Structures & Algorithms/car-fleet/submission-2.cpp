class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        // if(n==1){return 1;}
        vector<vector<int>>v(n,vector<int>(2));

        for(int i=0; i<n; i++){
            v[i] = {position[i],speed[i]};
        }
        sort(v.begin(), v.end());
        stack<float>st;
        for(auto i:v){
            float time = ((float)target-i[0])/i[1];
            st.push(time);
        }

        int ans = 0;
        float prev = st.top(); st.pop();
        while(!st.empty()){
            float curr = st.top();
            if(curr>prev){ans++;prev = curr;}
            st.pop();
        }

        return ans+1;
    }
};
