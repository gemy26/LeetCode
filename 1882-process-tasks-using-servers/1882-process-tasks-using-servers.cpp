class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using pil = pair<long long, int>;

        vector<int> ans;
        priority_queue<pil, vector<pil>, greater<pil>> free_servers,
            worker_servers;
        long long cur_time = 0;

        for (int i = 0; i < servers.size(); i++) {
            free_servers.push({servers[i], i});
        }

        for (int j = 0; j < tasks.size(); j++) {
            cur_time = max(cur_time, (long long)j);
            while (!worker_servers.empty() &&
                   worker_servers.top().first <= cur_time) {
                auto [_, idx] = worker_servers.top();
                worker_servers.pop();
                free_servers.push({servers[idx], idx});
            }
            if (free_servers.empty()) {
                cur_time = worker_servers.top().first;
                while (!worker_servers.empty() &&
                       worker_servers.top().first <= cur_time) {
                    auto [_, idx] = worker_servers.top();
                    worker_servers.pop();
                    free_servers.push({servers[idx], idx});
                }
            }
            auto [_, idx] = free_servers.top();
            ans.push_back(idx);
            worker_servers.push({tasks[j] + cur_time, idx});
            free_servers.pop();
        }
        return ans;
    }
};