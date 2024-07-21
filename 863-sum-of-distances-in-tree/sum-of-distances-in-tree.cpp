class Solution {
    
public:

   vector<vector<int>>adj;
   vector<int> nodes;
   vector<int>sub_tree;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        adj.resize(N);
        sub_tree.resize(N);
        nodes.resize(N);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        build_subtree(0, -1);
        dfs(0, -1);
        return sub_tree;
    }

    void build_subtree(int u, int par) {
        nodes[u] = 1;
        for(auto v : adj[u]){
        if(par == v) continue;
            build_subtree(v, u);
            nodes[u] += nodes[v];
            sub_tree[u] += sub_tree[v] + nodes[v];
            
        }
    }

    void dfs(int u, int par){
        for(auto v : adj[u]){
            if( par == v ) continue;
            sub_tree[v] = sub_tree[u] + ((int) nodes.size() - nodes[v] ) - nodes[v]; 
            dfs(v, u);
        }
    }

    
};