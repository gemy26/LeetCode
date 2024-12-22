template <typename T> struct sparse {
    int Log, n;
    vector<vector<T>> table;
    function<T(T, T)> merge;
    template <class U>
    explicit sparse(vector<T> arr, U merge)
        : merge(merge), n((int)arr.size()), Log(__lg(arr.size()) + 1),
          table(Log, vector<T>(n)) {
        table[0] = arr;
        for (int l = 1; l < Log; l++) {
            for (int i = 0; i + (1 << (l - 1)) < n; i++) {
                table[l][i] =
                    merge(table[l - 1][i], table[l - 1][i + (1 << (l - 1))]);
            }
        }
    }
    T query(int l, int r) {
        if (l > r)
            return {};
        int len = __lg(r - l + 1);
        return merge(table[len][l], table[len][r - (1 << len) + 1]);
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        sparse sp(heights, [](int i, int j) -> int {
            return max(i, j);
        });
        int n = heights.size();
        vector <int> ans(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int a = queries[i][0], b = queries[i][1];
            if(a > b) swap(a, b);
            if(a == b || heights[b] > heights[a]) ans[i] = b;
            else{
                int l = b, r = n, res = -1;
                while(r >= l){
                    int mid = (l + r) / 2;
                    //if(i == 1) cout << mid << " ";
                    if(sp.query(b, mid) > max( heights[b] , heights[a] )){
                        r = mid - 1;
                        res = mid;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                ans[i] = res;
            }
        }
        return ans;
    }
};