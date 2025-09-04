class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0];                  
        });
        int Y = INT_MIN;
        for (int i = 0; i < points.size(); i++) {
            Y = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][1] >= points[j][1] && Y < points[j][1]) {
                    ans++;
                    Y = points[j][1];
                }
            }
        }

        return ans;
    }
};