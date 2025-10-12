class Solution {
public:

    long long calc(int idx, vector<pair<long long,long long>> &v, vector<long long> &dp){
         if (idx >= v.size())
                return 0;

            long long& ret = dp[idx];
            if (~ret)
                return ret;

            long long op2 = calc(idx + 1, v, dp);

            int pos = lower_bound(
                v.begin(), v.end(),
                make_pair(v[idx].first + 3, 0LL)) - v.begin();

            long long op1 = v[idx].second + calc(pos, v, dp);

            return ret = max(op1, op2);
    }

    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> mp;
        for (int x : power)
            mp[x] += x;

        vector<pair<long long, long long>> v;
        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end());

        int n = (int)v.size();

        vector<long long> dp(n, -1);

        return calc(0, v, dp);
    }
};