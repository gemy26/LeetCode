class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        auto v = vector <long long> (nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            v[i] += v[i - 1] ;
        }

        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1, f = -1, mid;
            while (r >= l) {
                mid = l + (r - l) / 2;
                long long  range = mid - i + 1;
                long long sum = v[mid] - (i ? v[i - 1] : 0);
                //cout << i << " " << mid << " " << range <<" "<< sum << endl;
                if (range * sum < k) {
                    l = mid + 1;
                    f = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (~ f) {
                ans += (f - i + 1);
            }
        }
        return ans;
    }
};