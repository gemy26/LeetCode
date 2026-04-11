class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> s;
        int ans = 0, n = height.size();
        for(int i = 0; i < n; i ++){
            while(!s.empty() && height[s.top()] <= height[i]){
                int mid = s.top();
                s.pop();
                if(!s.empty()){
                    int h = min(height[i], height[s.top()]) - height[mid];
                    int w = i - s.top() - 1;
                    ans += (w * h);
                }
            }
            s.push(i);
        }
        return ans;
    }
};