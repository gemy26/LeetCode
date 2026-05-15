class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // BS on the smaller array and try to construct the left half of the two
        // arays merged together
        if(a.size() > b.size()) swap(a, b);
        int n = a.size(), m = b.size();
        int half = (n + m + 1) / 2;
        int l = 0, r = n;
        while(r >= l){
            int mid = (l + r) / 2;
            int l1 = mid > 0 ? a[mid - 1] : INT_MIN;
            int r1 = mid < a.size() ? a[mid] : INT_MAX;
            int l2 = half - mid > 0 ? b[half - mid - 1] : INT_MIN;
            int r2 = half - mid < b.size() ? b[half - mid] : INT_MAX;
            if(l1 <= r2 && l2 <= r1){
                if((n + m) % 2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }else{
                    return max(l1, l2);
                }
            }
            else if(r2 < l1){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return 0.0;
    }
};