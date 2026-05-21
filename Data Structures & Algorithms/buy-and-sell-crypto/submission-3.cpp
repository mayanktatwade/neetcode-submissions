class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int p : prices) {
            minPrice = min(minPrice, p);           // update min price
            maxProfit = max(maxProfit, p - minPrice); // best profit so far
        }

        return maxProfit;
    }
};
