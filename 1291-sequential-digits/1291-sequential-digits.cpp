class Solution {
public:
    vector <int> constructArray(){
        vector <int> arr;
        for(int i = 1; i <= 9; i ++){ 
            int num = i;
            for(int j = i + 1; j <= 9; j ++){ 
                num *= 10;
                num += j;
                // cout << num << " ";
                arr.push_back(num);
            }
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector <int> ans;
        vector <int> nums = constructArray();
        auto l = lower_bound(nums.begin(), nums.end(), low) - nums.begin();
        auto r = upper_bound(nums.begin(), nums.end(), high) - nums.begin() - 1;
        // cout << nums[l] << " " << nums[r];
        for(int i = l; i <= r; i ++) {
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};