class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& a,
                                     vector<vector<int>>& queries) {

        vector<int> indegree(n, 0), level(n, 0);
        queue<pair<int, int>> q; // node level
        vector<bool> ans;
        vector<vector<int>> adj(n);
        map<int, set<int>> mp;

        for (auto i : a) {
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push({i, 0});
                level[i] = 0;
            }
        }

        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            level[node] = lvl;
            for (auto v : adj[node]) {
                mp[v].insert(node);
                for(auto i : mp[node]){
                    mp[v].insert(i);
                }
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push({v, lvl + 1});
                }
            }
        }

        for (auto q : queries) {
            int u = q[0], v = q[1];
            // if (level[v] > level[u]) {
            //     ans.push_back(true);
            // } else {
            //     ans.push_back(false);
            // }
            ans.push_back(mp[v].count(u) == 1);
        }
        return ans;
    }
};