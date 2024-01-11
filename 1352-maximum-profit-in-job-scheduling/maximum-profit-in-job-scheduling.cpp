class Solution {
public:
vector<int>dp;
int solve(int idx,int n,vector<vector<int>>& data){
    if(idx >= n)
        return 0;

    int res = 0;
    if(dp[idx] != -1)
        return dp[idx];

    res = solve(
        idx+1,n,data
        );
   vector<int>tmp(3,0);
        tmp[0] = data[idx][1];
        int next_idx = lower_bound(data.begin(),data.end(),tmp)-data.begin();
   res = max(
       res,
       data[idx][2]+solve(next_idx,n,data)
   );

    return dp[idx] = res;

}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = (int)startTime.size();
        dp.resize(n,-1);
        vector<vector<int>>data(n,vector<int>(3));
        for(int i  =0; i < n ; i++){
            data[i][0] = startTime[i];
            data[i][1] = endTime[i];
            data[i][2] = profit[i]; 
            
        }
        sort(data.begin(),data.end());
          return solve(0,n,data);
          
         
        
    }
};