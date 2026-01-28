class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Dijkstra
        vector <vector <pair<int, int>>> adj(n + 1);
        vector <int> dist(n, 100000000);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < edges.size(); i ++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first;  
            int u = top.second; 

            if (d > dist[u])
            continue;

            for(auto [v, w] : adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == 100000000 ? -1 : dist[n - 1];
    }
};