class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, ans = -1;
        while(l < r){
            ans = max(ans, min(height[l], height[r]) * (r - l));
            cout << l << "  " << r << endl;
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