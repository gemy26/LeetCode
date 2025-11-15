class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        stack <int> stk; //index
        for(int i = 0; i <= n ; i ++){
            while(!stk.empty() && (i == n || v[i] <= v[stk.top()])){
                int height = v[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, height * width);
            }
            stk.push(i);
        }
        return ans;
    }
};