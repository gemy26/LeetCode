class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
        int sum = 0, ans = 0;
        int pos_sum = 0, neg_sum = 0;
        int max_pos_sum = 0, min_neg_sum = 1e9;
        for(int i = 0; i < v.size(); i ++){
            if(pos_sum + v[i] < 0){
                pos_sum = 0;
            }
            else{
                pos_sum += v[i];
            }
            if(neg_sum + v[i] > 0){
                neg_sum = 0;
            }
            else{
               neg_sum += v[i];
            }
            max_pos_sum = max(pos_sum, max_pos_sum);
            min_neg_sum = min(min_neg_sum, neg_sum);
        }
        return max(abs(min_neg_sum), max_pos_sum);
    }
};