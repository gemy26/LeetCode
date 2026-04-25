class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // arr[i] = (frq[nums[i]] - 1) * i - sum + i 
        int n = nums.size();
        vector <long long> arr(n, 0);
        map <int, int> frq;
        map <int, long long> sum;
        for(int i = 0; i < n; i ++){
            arr[i] += frq[nums[i]] * i - sum[nums[i]];
            frq[nums[i]] ++;
            sum[nums[i]] += i;
        }
        frq.clear();
        sum.clear();
        for(int i = n - 1; i >= 0; i --){
             arr[i] += sum[nums[i]] - frq[nums[i]] * i;
            frq[nums[i]] ++;
            sum[nums[i]] += i;
        }
        return arr;
    }
};