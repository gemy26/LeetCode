class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0, j = 0;
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i <= 1e5; i++) {
            while (j < events.size() && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i)
                pq.pop();

            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};