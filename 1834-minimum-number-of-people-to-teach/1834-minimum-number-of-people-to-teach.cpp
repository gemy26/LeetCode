class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {

        map<int, set<int>> knows;
        set<int> noConn;
        int ans = 1e9;

        for (int i = 0; i < languages.size(); i++) {
            for (auto j : languages[i]) {
                knows[i + 1].insert(j);
            }
        }

        // get all relationships that cannot communicate with each others and
        // brute force over the languages and count the minimum

        for (auto friendship : friendships) {
            int u = friendship[0], v = friendship[1];
            bool can = false;
            for (auto lang : languages[u - 1]) {
                if (knows[v].count(lang)) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                noConn.insert(v);
                noConn.insert(u);
            }
        }

        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (auto u : noConn) {
                if (knows[u].count(lang) == 0) {
                    cnt++;
                }
            }
            ans = min(cnt, ans);
        }

        return ans;
    }
};