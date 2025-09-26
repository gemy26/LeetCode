class Solution {
public:
    int triangleNumber(vector<int>& v) {
        // a + b > c 
        // n^2 log(n)
        int ans = 0;

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i ++){
            for(int j = i + 1; j < v.size(); j ++){
                int sum = v[i] + v[j];
                int pos = lower_bound(v.begin() + j + 1, v.end(), sum)
                 - v.begin();
               
                // cout << i << " " << j << " " << pos << endl;
                ans += (pos - j - 1);
            }
        }
        return ans;
    }
};