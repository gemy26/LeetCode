class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Solution1// N*log(N)
        //  max suffix to get the max from i->n
        //  i->n and do BS to get the next start after current end
        int n = events.size();
        vector<int> max_suff(n + 1, 0);
        sort(events.begin(), events.end());
        max_suff[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            max_suff[i] = max(events[i][2], max_suff[i + 1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i ++){
            ans = max(ans, events[i][2]);
            int l = i + 1, r = n - 1, found = -1;
            while(r >= l){
                int mid = (l + r) / 2;
                if(events[mid][0] >= events[i][1] + 1){
                    r = mid - 1;
                    found = mid;
                }else{
                    l = mid + 1;
                }
            }
            if(~found){
                ans = max(ans, events[i][2] + max_suff[found]);
            }
        }
        return ans;
    }
};