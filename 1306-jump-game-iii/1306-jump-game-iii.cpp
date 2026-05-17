class Solution {
public:
    vector <bool> vis;
    void dfs(int node, vector <int> &arr){ //node -> index
        if(vis[node]) return;
        vis[node] = true;
        if(node + arr[node] < arr.size()){
            dfs(node + arr[node], arr);
        }
        if(node - arr[node] >= 0){
            dfs(node - arr[node], arr);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        vis = vector <bool> (5e4 + 5, false);
        dfs(start, arr);
        for(int i = 0; i < arr.size(); i ++){
            if(arr[i] == 0 && vis[i]){
                return true;
            }
        }
        return false;
    }
};