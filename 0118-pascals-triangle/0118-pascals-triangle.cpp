class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> pascal;
        vector <int> temp;
        pascal.push_back({1});
        if(numRows == 1) return pascal;
        pascal.push_back({1, 1});
        int idx = 1;
        while(numRows - 1 > idx) {
            temp.push_back(1);
            for(int i = 0; i + 1 < pascal[idx].size(); i ++){
                temp.push_back(pascal[idx][i] + pascal[idx][i + 1]);
            }
            temp.push_back(1);
            pascal.push_back(temp);
            temp.clear();
            idx ++;
        }
        return pascal;
    }
};