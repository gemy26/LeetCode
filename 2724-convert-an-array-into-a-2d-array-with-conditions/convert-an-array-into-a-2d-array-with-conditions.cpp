class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       map<int,int>mp;
       int max_rows = 0;
       for(int i = 0; i < nums.size() ;i++){
           mp[nums[i]]++;
           max_rows = max(max_rows,mp[nums[i]]);
       }
       vector<vector<int>>res(max_rows);
       for(int i = 0; i < max_rows ; i++)
        {
            for(auto &j : mp){
                if(j.second > 0){
                    res[i].push_back(j.first);
                    j.second--;
                }
            }
        } 
        return res;
    }
};