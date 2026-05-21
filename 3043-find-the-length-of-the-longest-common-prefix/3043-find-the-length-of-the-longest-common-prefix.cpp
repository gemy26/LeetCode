class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        map <int, bool> vis;
        for(auto i : arr1){
            int num = i;
            while (num > 0){
                vis[num] = true;
                num /= 10;
            }
        }

        for(auto i : arr2){
            int num = i;
            while (num > 0){
                if(vis.find(num) != vis.end()){
                    string s = to_string(num);
                    ans = max(ans, (int)s.size());
                }
                num /= 10;
            }
        }

        return ans;
    }
};