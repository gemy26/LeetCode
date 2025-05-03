class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = (int)tops.size(), ans = 1000000;
        for (int i = 1; i <= 6; i++) {
            int cnt = 0, i_cnt = 0;
            for (int j = 0; j < n; j++) {
                if (bottoms[j] == i && tops[j] != i) {
                    cnt++;
                    i_cnt++;
                    continue;
                }
                if (tops[j] == i)
                    i_cnt++;
            }
            if (i_cnt == n)
                ans = min(ans, cnt);
            cnt = 0, i_cnt = 0;
            for (int j = 0; j < n; j++) {
                if (bottoms[j] != i && tops[j] == i) {
                    cnt++;
                    i_cnt++;
                    continue;
                }
                if (bottoms[j] == i)
                    i_cnt++;
            }
            if (i_cnt == n)
                ans = min(ans, cnt);
        }
        return (ans == 1000000 ? -1 : ans);
    }
};