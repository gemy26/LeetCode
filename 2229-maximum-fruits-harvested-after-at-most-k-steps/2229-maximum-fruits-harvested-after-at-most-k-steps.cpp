class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        // if i moved x steps to left and i will move to right by y
        //  so i need x * 2 + y <= k
        //  try all compinations between x and y

        int n = fruits.size();
        vector<int> sum(n + 1);
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;

        for (int x = 0; x <= k / 2; x++) {
            int start = startPos - x;
            int end = k - (2 * x) + startPos;

            int left = lower_bound(indices.begin(), indices.end(), start) -
                       indices.begin();

            int right = upper_bound(indices.begin(), indices.end(), end) -
                        indices.begin();

            ans = max(ans, sum[right] - sum[left]);

            start = startPos - (k - 2 * x);
            end = startPos + x;

            left = lower_bound(indices.begin(), indices.end(), start) -
                       indices.begin();
            right = upper_bound(indices.begin(), indices.end(), end) -
                        indices.begin();

            ans = max(ans, sum[right] - sum[left]);
        }

        return ans;
    }
};