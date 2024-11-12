class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        
        int q = (int)queries.size();
        int n = (int)items.size();

        sort(items.begin(), items.end());

        vector<int> res(q);
        vector <int> prefix(n, 0);
        prefix[0] = items[0][1];
 
        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], items[i][1]);
        }

        for(int i = 0; i < n; i++) {
            cout << prefix[i] << " "; 
        }
        cout << endl;

        for (int j = 0; j < q; j++) {
            int l = 0, r = n - 1, mid, ans = -1;
            while(r >= l){
                mid = (l + r) / 2;
                if(items[mid][0] <= queries[j]){
                    l = mid + 1;
                    ans = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            cout << ans << " ";
            if(ans == -1){
                res[j] = 0;
            }
            else{
                res[j] = prefix[ans];
            }
        }
        return res;
    }
};