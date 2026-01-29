class Solution {
public:
    int findMin(vector<int>& nums) {
        // find the point 'x' where y y y x z z z z > x and y > x
        int l = 0, r = nums.size() - 1, ans = INT_MAX;
        while(r >= l){
            int mid = (l + r) / 2;
            cout << l << " " << r << " " << mid ; 
            ans = min(ans, nums[mid]);
            if(nums[mid] < nums[r]){ 
                cout << " case 1\n";
                r = mid - 1;
            }
            else{
                cout << " case 2\n";
                l = mid + 1;
            }
        }
        // cout << ans << endl;
        return ans;
    }
};