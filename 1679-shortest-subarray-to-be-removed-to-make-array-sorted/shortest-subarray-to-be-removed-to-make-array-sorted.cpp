class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0;
        int n = (int) arr.size();
        while(l + 1 < n && arr[l] <= arr[l + 1]) l++;
        if(l == n - 1) 
            return 0;
         
        int r = n - 1;
        while(r - 1 > 0 && arr[r] >= arr[r - 1]) r--;
        int ans = min(r, n - l - 1);

        int i = 0;
        while(i <= l && r < n){
            if(arr[i] <= arr[r]){
                ans = min(ans, r - i - 1);
                i ++;
            }
            else{
                r ++;
            }
        }
        return ans;
    }
};