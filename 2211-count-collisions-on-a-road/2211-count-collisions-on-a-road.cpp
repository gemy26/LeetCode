class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, R = 0;
        bool coll = 0;
        int n = directions.size();
        for (int i = 0; i < n; i++) {
            // cout << i << " " << R << " " << coll << " ";
            if (directions[i] == 'L') {
                if (R > 0) {
                    ans += R + 1;
                    R = 0;
                    coll = 1;
                } else if(coll){
                    ans ++;
                }
            } else if (directions[i] == 'S') {
                if (R >= 0) {
                    ans += R;
                    R = 0;
                }
                 coll = 1;
            } else if (directions[i] == 'R') {
               R ++;
               coll = 0;
            }
            // cout << ans << endl;
        }
        return ans;
    }
};