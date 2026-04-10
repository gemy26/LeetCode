class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int l = 0, r = n - 1;
        while (r >= l) {
            cout << l << " " << r << endl;
            int a = pow(nums[l], 2), b = pow(nums[r], 2);
            if (a > b) {
                ans.push_back(a);
                l++;
            } else if (b > a) {
                ans.push_back(b);
                r--;
            } else {
                ans.push_back(a);
                // ans.push_back(b);
                l++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};