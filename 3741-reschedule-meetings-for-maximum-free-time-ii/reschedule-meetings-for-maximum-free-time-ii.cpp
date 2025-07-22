class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 2), maxRight(n + 2, 0);

        gaps[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            int gap = startTime[i] - endTime[i - 1];
            gaps[i] = gap;
        }

        gaps[n] = eventTime - endTime.back();

        for (int i = n - 1; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], gaps[i + 1]);
        }

        int ans = gaps.back(), maxLeft = 0;
        for (int i = 1; i <= n; i++) {
            int duration = endTime[i - 1] - startTime[i - 1];
            if (maxRight[i] >= duration || maxLeft >= duration) {
                ans = max(ans, gaps[i] + gaps[i - 1] + duration);
            }
            ans = max(ans, gaps[i] + gaps[i - 1]);
            maxLeft = max(maxLeft, gaps[i - 1]);
        }

        return ans;
    }
};