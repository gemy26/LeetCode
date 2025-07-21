class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        
        int n = startTime.size(), ans = 0;
        vector <int> prefix(n + 1);
        for(int i = 0; i < n; i ++){
            prefix[i + 1] = prefix[i] + endTime[i] - startTime[i]; 
        }

        for (int i = k - 1; i < n; i++) {
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            int left = i == k - 1 ? 0 : endTime[i - k];
            ans = max(ans, right - left - (prefix[i + 1] - prefix[i - k + 1]));
        }
        
        return ans;
    }
};