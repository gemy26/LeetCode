class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // use min heap to get ride of min prefix and keep yout current sum
        // greater than or equal current state
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
        pq.push({0, -1});
        long long l = 0, r = 0, ans = INT_MAX, sum = 0, prefix = 0;
        while (r < nums.size()) {
            prefix += nums[r];
            while (!pq.empty() && prefix - pq.top().first >= k) {
                ans = min(ans, r - pq.top().second);
                pq.pop();
            }
            pq.push({prefix, r});
            r++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};