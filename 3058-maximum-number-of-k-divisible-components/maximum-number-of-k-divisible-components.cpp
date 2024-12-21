class Solution {
public:
    int comp_cnt = 0;
    vector <long long> sub_tree;
    void calc(int node, int par, vector<vector<int>>& adj, int k) {
        for (auto it : adj[node]) {
            if (it != par) {
                //cout << node << " " << par << endl;
                calc(it, node, adj, k);
                sub_tree[node] += sub_tree[it];
            }
        }
        if(sub_tree[node] % k == 0){
            comp_cnt ++;
            sub_tree[node] = 0;
        }
    }

     

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n + 1);
        sub_tree.resize(n + 1, 0);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 0; i < values.size(); i++) {
            sub_tree[i] = values[i] * 1LL;
        } 
        comp_cnt = 0;
        calc(0, -1, adj, k);
        //dfs(0, -1, adj, k);
       
        return comp_cnt ;
    }
};