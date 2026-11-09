class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        vector <pair<int, int>> sortedQueries;
        for(int i = 0; i < queries.size(); i ++) {
            sortedQueries.push_back({ queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector <int> ans(queries.size());
        int l = 0, r = 0;
        vector <int> frq(n + 1, 0);
        int active = 0;
        for(auto& [q, i] : sortedQueries) {
            int start = q - x;
            while(r < logs.size() && logs[r][1] <= q) {
                if(frq[logs[r][0]] ++ == 0) {
                    active ++;
                }
                r ++;
            }
            while(l < r && logs[l][1] < start) {
                frq[logs[l][0]]  --;
                if(frq[logs[l][0]] == 0) {
                    active --;
                }
                l ++;
            }
            ans[i] = n - active;
        }
        return ans;
    }
};