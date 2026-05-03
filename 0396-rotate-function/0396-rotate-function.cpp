class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // 0*arr0 + 1*arr1 + 2*arr2
        // 0*arr2 + 1 *arr0 + 2*arr1
        //...
        // increase sumNumbers and add arri*n

        int sumNumbers = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int ans = 0, init = 0;
        for(int i = 0; i < n; i ++){
            init += (i * nums[i]);
        }
        ans = init;
        for(int i = n - 1; i > 0; i --){
            init += sumNumbers - (nums[i] * n);
            ans = max(ans, init);
        }
        return ans;
    }
};