class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int all_even = 0, all_odd = 0, end_even = 0, end_odd = 0;
        for(auto i : nums){
            if(i & 1){
                all_odd ++;
                end_odd = max(end_odd, 1 + end_even);
            }
            else if(i % 2 == 0){
                all_even ++;
                end_even = max(end_even, 1 + end_odd);
            }
        }
        return max({all_even, all_odd, end_even, end_odd});
    }
};