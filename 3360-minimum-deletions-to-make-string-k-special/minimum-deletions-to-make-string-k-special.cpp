class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector <int> frq(27, 0), prefix(27, 0);
        int ans = 1e9;

        for(auto i : word){
            frq[i - 'a'] ++;
        }

        frq.erase(remove(frq.begin(),frq.end(),0),frq.end());

        for(int i = 0; i < frq.size(); i ++){
            int sum = 0;
            for(int j = 0; j < frq.size(); j ++){
                if(i == j) continue;
                if(frq[j] < frq[i]) sum += frq[j];
                else if(frq[j] > k + frq[i]){
                    sum += frq[j] - (frq[i] + k);
                }
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};