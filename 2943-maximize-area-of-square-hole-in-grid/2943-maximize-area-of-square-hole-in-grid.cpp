class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int curh = 1, maxh = 1;
        int curv = 1, maxv = 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        for(int i = 1; i < hBars.size(); i ++){
            if(hBars[i] == hBars[i - 1] + 1){
                curh ++;
            }
            else{
                curh = 1;
            }
            maxh = max(maxh, curh);
        }

        for(int i = 1; i < vBars.size(); i ++){
            if(vBars[i] == vBars[i - 1] + 1){
                curv ++;
            }
            else{
                curv = 1;
            }
            maxv = max(maxv, curv);
        }

        int len = min(maxh, maxv) + 1;
        return len * len;
    }
};