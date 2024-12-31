class Solution {
public:
   int calc(int idx, vector <int> &dp, vector <int> &days, vector <int> &costs){
    if(idx >= days.size())
        return 0;
    int &ret = dp[idx];
    if(~ret)
        return ret;
    ret = 1e9;
    ret = min({
        costs[0] + calc(idx + 1, dp, days, costs),
        costs[1] + calc(lower_bound(days.begin(), days.end(), days[idx] + 7) - days.begin(), dp, days, costs),
        costs[2] + calc(lower_bound(days.begin(), days.end(), days[idx] + 30) - days.begin(), dp, days, costs),
    });
    return ret;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector <int> dp(n, -1);
        int ans = calc(0, dp, days, costs); //index, day, vector
        return ans;
    }
};