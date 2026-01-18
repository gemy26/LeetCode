class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rowsum(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> colsum(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; ++i) {
            rowsum[i][0] = grid[i][0];
            for (int j = 1; j < m; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }

        for(int j = 0; j < m; j ++){
            colsum[0][j] = grid[0][j];
            for(int i = 1; i < n; i ++){
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        int max_k = 0;
        for (int k = 1; k <= min(n, m); k++) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    int stdsum =
                        rowsum[i][j + k - 1] - (j - 1 >= 0 ? rowsum[i][j - 1] : 0);
                    bool check = true;

                    // check all rows
                    for (int ii = i + 1; ii < i + k; ii++) {
                        check &= (rowsum[ii][j + k - 1] -
                                      (j - 1 >= 0 ? rowsum[ii][j - 1] : 0) ==
                                  stdsum);
                    }

                    // check all cols
                    for (int jj = j; jj < j + k; jj++) {
                        check &= (colsum[i + k - 1][jj] -
                                      (i - 1 >= 0 ? colsum[i - 1][jj] : 0) ==
                                  stdsum);
                    }

                    int d1 = 0, d2 = 0;
                    for (int kk = 0; kk < k; kk++) {
                        d1 += grid[i + kk][j + kk];
                        d2 += grid[i + kk][j + k - 1 - kk];
                    }

                    if (check && d1 == d2 && d1 == stdsum) {
                        max_k = max(max_k, k);
                    }
                }
            }
        }
        return max_k;
    }
};