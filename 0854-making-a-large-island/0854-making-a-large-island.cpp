class Solution {
public:
    class DisjointSets {
    private:
        vector<int> parents;
        vector<int> sizes;

    public:
        DisjointSets(int size) : parents(size), sizes(size, 1) {
            for (int i = 0; i < size; i++) {
                parents[i] = i;
            }
        }

        /** @return the "representative" node in x's component */
        int find(int x) {
            return parents[x] == x ? x : (parents[x] = find(parents[x]));
        }

        /** @return whether the merge changed connectivity */
        bool unite(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);
            if (x_root == y_root) {
                return false;
            }

            if (sizes[x_root] < sizes[y_root]) {
                swap(x_root, y_root);
            }
            sizes[x_root] += sizes[y_root];
            parents[y_root] = x_root;
            return true;
        }

        /** @return whether x and y are in the same connected component */
        bool connected(int x, int y) { return find(x) == find(y); }
        int getSize(int x) { return sizes[find(x)]; }
    };
    int M;
    int HashPoint(int x, int y) {
        return x * M + y;
    }
    bool IsValid(int n, int m, int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        M = m;
        DisjointSets dsu(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k] + i;
                        int y = dy[k] + j;
                        if (IsValid(n, m, x, y) && grid[x][y] == 1) {
                            dsu.unite(HashPoint(i, j), HashPoint(x, y));
                        }
                    }
                }
            }
        }
        int ans = 0, Zero = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    Zero = 1;
                    set <int> unique_parents;
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k] + i;
                        int y = dy[k] + j;
                        if (IsValid(n, m, x, y) && grid[x][y] == 1) {
                           // int sz = dsu.getSize(HashPoint(x, y));
                            //ne += sz;
                            unique_parents.insert(dsu.find(HashPoint(x, y)));
                        }
                    }
                    int ne = 1;
                    for(auto p : unique_parents){
                        ne += dsu.getSize(p);
                    }
                    ans = max(ans, ne);
                    unique_parents.clear();
                } 
            }
        }
        if(!Zero){
            ans = n * m;
        }
        return ans;
    }
};