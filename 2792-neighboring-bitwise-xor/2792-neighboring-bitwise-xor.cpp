class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size();
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            if (d[i] == 0) {
                a[(i + 1) % n] = a[i];
                b[(i + 1) % n] = b[i];
            } else {
                a[(i + 1) % n] = !a[i];
                b[(i + 1) % n] = !b[i];
            }
        }

        // for (int i = 0; i + 1 <= n; i++) {
        //     cout << b[i] << " " << b[(i + 1) % n] << '\n';
        // }
        bool ans1 = true, ans2 = true;
        for (int i = 0; i + 1 <= n; i++) {
            // cout << a[i] << " ";
            ans1 &= ((a[i] ^ a[(i + 1) % n]) == d[i]);
            ans2 &= ((b[i] ^ b[(i + 1) % n]) == d[i]);
        }

        return ans1 || ans2;
    }
};