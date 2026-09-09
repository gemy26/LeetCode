class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zeroRows, zeroColums;
        int n = matrix.size(), m = matrix[0].size();
        // vector<bool> isZeroRow(n, false), isZeroCol(m, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroColums.insert(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(zeroRows.find(i) != zeroRows.end() || zeroColums.find(j) != zeroColums.end())
                    matrix[i][j] = 0;
                    // matrix[j][i] = 0;
                }
        }
    }
};