class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        // dfs and get xor for each subtree and then brute force on all edges to
        // get the target result
        int n = nums.size(), ans = 100000000;
        vector<int> XOR(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<set<int>> descendants(n + 1, set<int>());
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, XOR, adj, nums, descendants);

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xor1, xor2, xor3;
                if (descendants[i].count(j)) {
                    xor1 = XOR[j];
                    xor2 = XOR[i] ^ XOR[j];
                    xor3 = XOR[0] ^ XOR[i];
                } else if (descendants[j].count(i)) {
                    xor1 = XOR[i];
                    xor2 = XOR[i] ^ XOR[j];
                    xor3 = XOR[0] ^ XOR[j];
                } else {
                    xor1 = XOR[i];
                    xor2 = XOR[j];
                    xor3 = XOR[0] ^ XOR[i] ^ XOR[j];
                }
                ans =
                    min(ans, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
            }
        }
        return ans;
    }
    void dfs(int v, int par, vector<int>& XOR, vector<vector<int>>& adj,
             vector<int>& nums, vector<set<int>>& descendants) {
        XOR[v] = nums[v];
        descendants[v].insert(v);
        for (int u : adj[v]) {
            if (u != par) {
                dfs(u, v, XOR, adj, nums, descendants);
                XOR[v] ^= XOR[u];
                descendants[v].insert(descendants[u].begin(),
                                      descendants[u].end());
            }
        }
    }
};