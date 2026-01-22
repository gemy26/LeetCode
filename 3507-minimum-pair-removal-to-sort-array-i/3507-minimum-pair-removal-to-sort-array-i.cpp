class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int op = n;
        int ans = 0;
        while (--op) {
            bool isAsc = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] >= nums[i - 1])
                    continue;
                else
                    isAsc = false;
            }
            if (!isAsc) {
                int minSum = 1e9;
                int f, s;
                for (int i = 0; i + 1 < nums.size(); i++) {
                        if (nums[i] + nums[i + 1] < minSum) {
                            minSum = min(minSum, nums[i] + nums[i + 1]);
                            f = i, s = i + 1;
                        }
                }
                cout << f << " " << s << endl;
                nums[f] = minSum;
                nums.erase(nums.begin() + s);
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};