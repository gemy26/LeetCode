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

        vector <int> components(){
            return parents;
        }

        /** @return whether x and y are in the same connected component */
        bool connected(int x, int y) { return find(x) == find(y); }
    };
    int countComponents(vector<int>& a, int th) {
        // all multiples for the same number less than thresold in the same
        // component any component has gcd for all its elements = 1 with the
        // other component if an element has gcd > 1 with other element in
        // another component so the lcm still <= threshold so we can merge all
        // components together
        sort(a.begin(), a.end());
        DisjointSets dsu(200005);
        int ans = 0, f = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > th) {
                ans++;
                //cout << "here 1\n";
                continue;
            }
            for (int j = a[i]; j <= th; j += a[i]) {
                dsu.unite(j, a[i]);
            }
        }
        
        set <int> st;
        for(int i = 0; i < a.size(); i ++){
            if(a[i] <= th)
                st.insert(dsu.find(a[i]));
        }
        return st.size() + ans;
    }
};