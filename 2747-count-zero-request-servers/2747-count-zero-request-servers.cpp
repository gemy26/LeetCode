class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = queries.size();

        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });

        // Store queries along with their original indices
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < m; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(m);
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (auto& [q, idx] : sortedQueries) {

            int startTime = q - x;

            // Include logs with time <= q
            while (right < logs.size() && logs[right][1] <= q) {
                int server = logs[right][0];

                if (freq[server] == 0) {
                    activeServers++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs with time < q - x
            while (left < right && logs[left][1] < startTime) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Servers without requests in the interval
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};