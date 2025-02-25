class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long  ans = 0, even = 1, odd = 0, sum = 0;
        const int mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i ++){
           sum += arr[i];
           if(sum % 2 == 0){
            ans += odd;
            ans %= mod;
            even ++;
           }
           else{
            ans += even;
            ans %= mod;
            odd ++;
           }
        }
        return ans;
    }
};