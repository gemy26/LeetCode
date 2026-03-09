class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(auto i : n){
            string dig = to_string(i - '0');
            ans = max(ans, stoi(dig));
        }
        return ans;
    }
};