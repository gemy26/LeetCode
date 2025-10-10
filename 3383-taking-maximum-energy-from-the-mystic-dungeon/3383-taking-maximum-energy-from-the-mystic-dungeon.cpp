class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = (int) energy.size();
        vector <int> dp(n);
        
        int ans = INT_MIN;
        for(int i = 0; i < n; i ++){
            if(i >= k){
                dp[i] = max(energy[i], energy[i] + dp[i - k]);
            }else{
                dp[i] = energy[i];
            }
        }

       for (int i = dp.size() - k; i < dp.size(); i++) 
            ans = max(ans, dp[i]);

        return ans;
    }
};