class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int) height.size();
        int l = 0, r = n - 1, ans = 0;
        while(r > l){
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if(height[l] > height[r]){
                r --;
            }
            else if(height[l] < height[r]){
                l ++;
            }
            else{
                l ++, r --;
            }      
        }

        return ans;
    }
};