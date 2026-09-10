class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans = 1e9,  l = *max_element(weights.begin(), weights.end()), r = 1e9;
        while(r >= l) {
            int mid = (l + r) / 2;
            int count_days = 0, curr_weight = 0;
            for(int i = 0; i < n; i ++){
                if(curr_weight + weights[i] > mid) {
                    curr_weight = 0;
                    count_days ++;
                }
                curr_weight += weights[i];
            }
            if (curr_weight) count_days ++;
            cout << mid <<  " " << count_days <<  " " << curr_weight << endl;
            if(count_days <= days){
                r = mid - 1;
                ans = mid;
            } else{
                l = mid + 1;
            }
        }
        return ans;
    }
};