class Solution {
public:
    vector<vector<int>> dist;
    vector<vector<pair<int, int>>> adj;

    void Dijkstra(char src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int node = src;
        dist[node][node] = 0;
        pq.push({0, node});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int u = top.second;

            for (auto [v, w] : adj[u]) {
                if (dist[node][v] > w + dist[node][u]) {
                    dist[node][v] = w + dist[node][u];
                    pq.push({dist[node][v], v});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        // Dijkstra from each start character and loop over source and get the
        // sum of changes to make source[i] -> target[i] and -1 if there is no
        // path

        dist = vector<vector<int>>(27, vector<int>(27, INT_MAX));
        adj = vector<vector<pair<int, int>>>(27);

        for (int i = 0; i < original.size(); i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        for (int i = 0; i < 27; i++)
            Dijkstra(i);

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                long long dis = dist[source[i] - 'a'][target[i] - 'a'];
                if (dis == INT_MAX)
                    return -1;
                ans += dis;
            }
        }

        return ans;
    }
};