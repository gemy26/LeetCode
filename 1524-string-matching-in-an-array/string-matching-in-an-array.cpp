class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set <string> st;
        for (int i = 0; i < words.size(); i ++) {
            for (int j = 0; j < words.size(); j ++) {
                if(i == j) continue;
                if(words[i].find(words[j]) != -1 ){
                    st.insert(words[j]);
                }
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};