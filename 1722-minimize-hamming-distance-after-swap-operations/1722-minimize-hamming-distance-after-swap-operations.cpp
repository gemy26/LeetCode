class Solution {
public:
    vector <int> par, sz;
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void join(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b); //a is the smaller
        par[a] = b;
        sz[b] += sz[a]; 
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        par = vector <int> (n + 1, 0);
        sz = vector <int> (n + 1, 0);
        for(int i = 0; i < n; i ++){
            par[i] = i;
            sz[i] = 1;
        }

        for(auto pair : allowedSwaps){
            join(pair[0], pair[1]);
        }

        map<int, map<int, int>> mp;
        for(int i = 0; i < n; i ++){
            int par = find(i);
            mp[par][source[i]] += 1;
            cout << i << " " << par << endl;
        }
        cout << "---------\n";
        int ans = 0;
        for(int i = 0; i < n; i ++){
            cout << i << " " << find(i) << endl;
            if(mp[find(i)][target[i]]){
                mp[find(i)][target[i]] -= 1;
            } else{
                ans ++;
            }
        }
        return ans;
    }
};