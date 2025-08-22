class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        //mix X, y   max X,Y containing ones 
        vector <int> dim{1000, 1000, 0, 0};
        for(int i = 0; i < grid.size(); i ++){
            for(int j = 0; j < grid[i].size(); j ++){
                if(grid[i][j] == 1){
                    dim[0] = min(dim[0], i);
                    dim[1] = min(dim[1], j);
                    dim[2] = max(dim[2], i);
                    dim[3] = max(dim[3], j);
                }
            }
        }
        cout << dim[0] << " " << dim[1] << " " << dim[2] << " " << dim[3] << endl;
        return (dim[2] - dim[0] + 1) * (dim[3] - dim[1] + 1);
    }
};