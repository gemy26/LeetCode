class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> sufMax(n, 0), prefMax(n, 0);
        for(int i = 0; i < n; i ++) prefMax[i] = i ? max(prefMax[i - 1], height[i]) : height[i];
        
        sufMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i --) sufMax[i] = max(sufMax[i + 1], height[i]);
        int ans = 0;
        for(int i = 1; i < n - 1; i ++){
            // cout << sufMax[i] <<  " " << prefMax[i] << endl;
            ans += (min(sufMax[i], prefMax[i]) - height[i]);
        }
        return ans;
    }
};