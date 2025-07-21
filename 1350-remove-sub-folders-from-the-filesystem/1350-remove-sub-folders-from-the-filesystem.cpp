class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector <string> ans;
        set <string> st;
        for(int i = 0; i < folder.size(); i ++){
            string cur = "";
            bool f = true;
            for(int j = 0; j < folder[i].size(); j ++){
                if(folder[i][j] == '/'){
                    if(st.count(cur)){
                        f = false;
                        break;
                    }
                }
                cur += folder[i][j];
                // cout << cur << endl;
            }
            if(f){
                ans.push_back(folder[i]);
                st.insert(folder[i]);
            }
        }
        return ans;
    }
};