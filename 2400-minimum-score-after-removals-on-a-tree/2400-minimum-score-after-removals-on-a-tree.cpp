class Solution {
public:
    vector<int>in;
    vector<int>out;
    bool isAncestor(int u, int v){
        return (in[u] <= in[v] && out[u] >= out[v]);
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        // dfs and get xor for each subtree and then brute force on all edges to
        // get the target result
        
        int n = nums.size(), ans = 100000000;
        vector<int> XOR(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<set<int>> descendants(n + 1, set<int>());

        in.clear();
        in.resize(n, 0);
        out.clear();
        out.resize(n, 0);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int timer = 0;
        dfs(0, -1, XOR, adj, nums, descendants, timer);

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xor1, xor2, xor3;
                if (isAncestor(i, j)) {
                    xor1 = XOR[j];
                    xor2 = XOR[i] ^ XOR[j];
                    xor3 = XOR[0] ^ XOR[i];
                } else if (isAncestor(j, i)) {
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
             vector<int>& nums, vector<set<int>>& descendants, int& timer) {
        XOR[v] = nums[v];
        in[v] = ++timer;
        // descendants[v].insert(v);
        for (int u : adj[v]) {
            if (u != par) {
                dfs(u, v, XOR, adj, nums, descendants, timer);
                XOR[v] ^= XOR[u];
                // descendants[v].insert(descendants[u].begin(),
                                    //   descendants[u].end());
            }
        }
        out[v] = ++timer;
    }
};