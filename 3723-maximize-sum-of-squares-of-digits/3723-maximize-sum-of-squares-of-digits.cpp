class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int total = 0;
        for(int i = 0; i < num; i ++) { 
            int x = sum - total;
            if(x > 9) {
                ans += "9";
                total += 9;
            } else{
                ans += to_string(x);
                total += x;
            }
        }
        if(sum != total) return "";
        return ans;
    }
};