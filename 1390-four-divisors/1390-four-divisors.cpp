class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            int cnt = 0;
            int sum = 0;
            for(int j = 1; j <= sqrt(num); j ++){
                if(num % j == 0){
                    if(num / j == j){
                        sum += j;
                        cnt ++;
                    }
                    else{
                        sum += j;
                        sum += (num / j);
                        cnt += 2;
                    }
                }
            }
            if(cnt == 4){
                ans += sum;
            }
        }
        return ans;
    }
};