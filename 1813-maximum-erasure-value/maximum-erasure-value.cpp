class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set <int> st;
        int ans = 0, i = 0, j = 0, n = (int) nums.size(), sum = 0;
        while(i < n && j < n){
            sum += nums[j];
            while(j < n && st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i ++;
            }
            ans = max(ans, sum);
            st.insert(nums[j]);
            j ++;
        }
        return ans;
    }
};