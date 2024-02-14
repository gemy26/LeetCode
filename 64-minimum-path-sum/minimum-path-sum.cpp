class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i =0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            int a=1e9,b=1e9;
            if(i > 0 && i <= n-1 ){
                a = grid[i-1][j];
            }
            if(j > 0 && j <= m-1){
                b = grid[i][j-1];
            }
            if(a != 1e9 || b != 1e9)
              grid[i][j] += min(a,b);
        }
    }
    return grid[n-1][m-1];

    }
};