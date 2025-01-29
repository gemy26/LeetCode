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
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        DisjointSets dsu(edges.size() + 1);
        for (auto edge : edges) {
            auto [u, v] = make_pair(edge[0], edge[1]);
            if (dsu.connected(u, v)) {
                ans.push_back(u);
                ans.push_back(v);
            }

            dsu.unite(u, v);
        }
        return ans;
    }
};