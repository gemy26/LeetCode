class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector <int> Rows(n, 0), Cols(m, 0);
        map <int, pair <int, int>> mp;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m ; j ++){
                mp[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i < arr.size(); i ++){
            auto [row, col] = mp[arr[i]];
            Rows[row] ++;
            Cols[col] ++;
            if(Rows[row] == m || Cols[col] == n){
                return i;
            }
        }

        return arr.size();
    }
};