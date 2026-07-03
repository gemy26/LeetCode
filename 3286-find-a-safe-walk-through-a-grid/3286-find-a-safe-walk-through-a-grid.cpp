class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>pq;
        
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], 0, 0});

        while(!pq.empty()) {
            auto [w, x, y] = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i ++){
                int nx = dx[i] + x, ny = dy[i] + y;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (w + grid[nx][ny] >= dist[nx][ny]) continue;
                dist[nx][ny] = grid[nx][ny] + w;
                pq.push({dist[nx][ny], nx, ny});
            }

        }
        cout << dist[n-1][m - 1] << endl;
        return dist[n-1][m - 1] < health;
    }
};