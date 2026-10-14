class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> v(n);

        for(int i = 0; i < n; i++) {
            v[i] = {position[i], speed[i]};
        }

        sort(v.begin(), v.end());

        int ans = 0;
        double prev = 0;

        for(int i = n - 1; i >= 0; i--) {
            double time = (double)(target - v[i].first) / v[i].second;

            if(time > prev) {
                ans++;
                prev = time;
            }
        }

        return ans;
    }
};