class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector <int> prefix(n + 2, 0), ans(n);
        for(int i = 0; i < bookings.size(); i ++){
            int x = bookings[i][0], y = bookings[i][1], delta = bookings[i][2];
            prefix[x] += delta;
            prefix[y + 1] -= delta;
        }
        for(int i = 1; i <= n; i ++){
            prefix[i] += prefix[i - 1];
            ans[i - 1] = prefix[i];
        }
        return ans;
    }
};