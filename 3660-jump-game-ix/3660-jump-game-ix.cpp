class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        vector<int> suffMin(n), prefMax(n, 0);
        suffMin[n - 1] = nums[n - 1];

        prefMax[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        ans[n - 1] = prefMax[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
            if(prefMax[i] > suffMin[i + 1]){
                ans[i] = ans[i + 1];
            }
            else{
                ans[i] = prefMax[i];
            }
        }

        return ans;
    }
};