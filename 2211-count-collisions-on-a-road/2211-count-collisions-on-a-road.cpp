class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, R = -1;
        bool coll = 0;
        int n = directions.size();
        for (int i = 0; i < n; i++) {
            if (directions[i] == 'L') {
                if (R >= 0) {
                    ans += R + 1;
                    R = 0;
                }
            } else if (directions[i] == 'S') {
                if (R > 0) {
                    ans += R;
                }
                 R = 0;
            } else if (directions[i] == 'R') {
                if (R >= 0) {
                    R += 1;
                } else{
                    R = 1;
                }
            }
        }
        return ans;
    }
};