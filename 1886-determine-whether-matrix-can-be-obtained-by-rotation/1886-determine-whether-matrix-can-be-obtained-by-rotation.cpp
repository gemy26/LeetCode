class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                rotated[j][n - i - 1] = mat[i][j];
            }
        }
        return rotated;
    }
 
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // try the 4 forms of the matrix (original + 3 rotates)
        // compare with the target
        
        bool ans = false;
        
        for(int i = 1; i <= 4; i ++){
            ans |= (target == mat);
            mat = rotate(mat);
        }
        return ans;
    }
};