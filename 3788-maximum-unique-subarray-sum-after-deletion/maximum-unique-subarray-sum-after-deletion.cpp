class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        set <int> st;
        sort(nums.rbegin(), nums.rend());

        for(int i = 0; i < nums.size(); i ++){
            if(st.count(nums[i])) continue;
            sum += nums[i];
            ans = max(ans, sum);
            st.insert(nums[i]);
        }
        return ans;
    }
};