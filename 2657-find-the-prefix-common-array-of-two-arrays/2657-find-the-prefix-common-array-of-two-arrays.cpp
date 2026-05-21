class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> vis_a(n + 1, 0), vis_b(n + 1, 0), prefix(n, 0);
        for (int i = 0; i < n; i++) {
            vis_a[A[i]] = 1;
            vis_b[B[i]] = 1;
            if (A[i] == B[i]) {
                prefix[i]++;
            } else {
                if (vis_a[B[i]])
                    prefix[i]++;
                if (vis_b[A[i]])
                    prefix[i]++;
            }
            prefix[i] += (i ? prefix[i - 1] : 0);
        }
        return prefix;
    }
};