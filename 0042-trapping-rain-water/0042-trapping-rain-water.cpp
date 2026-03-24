class Solution {
public:
    int trap(vector<int>& height) {
        stack <pair <int, int>> s;
        int ans = 0, n = height.size();
        for(int i = 0; i < n; i ++){
            while(!s.empty() && height[i] > s.top().first){
                int mid = s.top().first;
                s.pop();
                if(!s.empty()){
                    int h = min(height[i], s.top().first) - mid; 
                    int w = (i - s.top().second - 1);
                    ans += h * w;
                }
            }
            s.push({height[i], i});
        }
        return ans;
    }
};