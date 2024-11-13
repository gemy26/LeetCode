class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx = -1e9, mn = 1e9, cur_mx = -1e9, cur_mn = 1e9, ans = 0;
        for (int i = 0; i < arrays[0].size(); i++) {
            mx = max(mx, arrays[0][i]);
            mn = min(mn, arrays[0][i]);
        }

        for (int i = 1; i < arrays.size(); i++) {
            cur_mx = -1e9, cur_mn = 1e9;
            for (int j = 0; j < arrays[i].size(); j++) {
                cur_mx = max(cur_mx, arrays[i][j]);
                cur_mn = min(cur_mn, arrays[i][j]);
            }
            ans = max({ans, abs(cur_mx - mn), abs(cur_mn - mx)});
            mx = max(mx, cur_mx);
            mn = min(mn, cur_mn);
        }

        return ans;
    }
};