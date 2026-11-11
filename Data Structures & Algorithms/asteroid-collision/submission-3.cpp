class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int idx = 1;
        int n = asteroids.size();

        st.push(asteroids[0]);
        while(idx<n){
            if(st.empty()){st.push(asteroids[idx]);idx++;continue;}
            int t = st.top();
            int x = asteroids[idx];
            if(t<0 || t*x>0){st.push(x);idx++;}
            else{
                if(abs(t)==abs(x)){st.pop();idx++;}
                else if(abs(t)<abs(x)){st.pop();}
                else{idx++;}
            }
        }
        
        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        n = ans.size();
        for(int i=0;i<n/2;i++){swap(ans[i],ans[n-1-i]);}
        return ans;
    }
};