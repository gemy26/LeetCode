class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        unordered_map<int, deque<int>> mp;
        unordered_map<int, int> groups;
        vector<int> ans(nums.size());
        vector <int> original = nums;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        mp[cnt].push_back(nums[0]);
        groups[nums[0]] = cnt;
        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i] - nums[i - 1]) > limit) {
                cnt++;
            }
            mp[cnt].push_back(nums[i]);
            groups[nums[i]] = cnt;
        }

       

        for (auto i : groups) {
            cout << i.first << " " << i.second << endl;
        }
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = mp[groups[original[i]]].front();
            mp[groups[original[i]]].pop_front();
        }
        return ans;
    }
};