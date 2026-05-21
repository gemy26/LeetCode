class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> vis(n + 1, 0), prefix(n, 0);
        for (int i = 0; i < n; i++) {
            vis[A[i]] ++;
            if(vis[A[i]] == 2) prefix[i] ++;
            vis[B[i]] ++;
            if(vis[B[i]] == 2) prefix[i] ++;
            
            prefix[i] += (i? prefix[i - 1]: 0);
        }
        return prefix;
    }
};