class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector <string> ans;
        vector <bool> taken(queries.size(), false);
        for(int i = 0; i < queries.size(); i ++){
            for(auto j : dictionary){
                int diff = 0;
                for(int k = 0; k < j.size(); k ++){
                    if(j[k] != queries[i][k]) {
                        diff ++;
                    }
                }
                if(diff <= 2 && !taken[i]){
                    ans.push_back(queries[i]);
                    taken[i] = true;
                }
            }
        }
        return ans;
    }
};