class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profit(n + 1);
        vector<long long> prefix(n + 1);

        for(int i = 0; i < n; i ++){
            profit[i + 1] = profit[i] + strategy[i] * prices[i];
            prefix[i + 1] = prices[i] + prefix[i];
        }
         
        long long ans = profit[n];
        long long res = 0;
        for(int i = 0; i + k <= n; i ++){
            long long old = profit[i + k] - profit[i];
            long long new_profit = prefix[i + k] - prefix[i + k / 2];
            res = max(res, new_profit - old);
        }
        return ans + res;
    }
};