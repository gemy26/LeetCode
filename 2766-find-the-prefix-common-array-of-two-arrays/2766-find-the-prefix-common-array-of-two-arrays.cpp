class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = (int) A.size();
        int frq[55] = {};
        vector <int> ans(n);
        for(int i = 0; i < n; i ++){
            frq[A[i]] ++;
            frq[B[i]] ++;
            int cnt = 0;
            for(int j = 1; j <= n; j ++){
                if(frq[j] == 2){
                    cnt ++;
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};