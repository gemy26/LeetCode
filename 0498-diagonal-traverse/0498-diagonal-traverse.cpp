class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int turn = 1, n = (int)mat.size() - 1;
        for (int i = 0; i < mat.size(); i++) {
            if (turn) {
                int row = i, col = 0;
                while (row >= 0 && col < mat[0].size()) {
                    cout << mat[row][col] << " ";
                    ans.push_back(mat[row][col]);
                    row--, col++;
                }
            } else {
                vector <int> temp;
                int row = i, col = 0;
                while (row >= 0 && col < mat[0].size()) {
                    // cout << mat[row][col] << " ";
                    temp.push_back(mat[row][col]);
                    row--, col++;
                }

                reverse(temp.begin(), temp.end());
                for(auto i : temp) ans.push_back(i);
            }
            turn ^= 1;
        }

        for (int i = 1; i < mat[0].size(); i++) {
            if (turn) {
                int row = n, col = i;
                while (col < mat[0].size() && row >= 0) {
                    cout << mat[row][col] << " ";
                    ans.push_back(mat[row][col]);
                    row--, col++;
                }
            } else {
                int row = n, col = i;
                vector <int> temp;
                while (col < mat[0].size() && row >= 0) {
                    temp.push_back(mat[row][col]);
                    row--, col++;
                }

                reverse(temp.begin(), temp.end());
                for(auto i : temp) ans.push_back(i);
            }
            turn ^= 1;
        }
        return ans;
    }
};