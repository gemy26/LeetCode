class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int> a, b;
        string s = "";
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] == '.') {
                a.push_back(stoi(s));
                s = "";
                continue;
            }
            s += v1[i];
        }
        a.push_back(stoi(s));
        s = "";
        for (int i = 0; i < v2.size(); i++) {
            if (v2[i] == '.') {
                b.push_back(stoi(s));
                s = "";
                continue;
            }
            s += v2[i];
        }
        b.push_back(stoi(s));

        // for(auto i : a) cout << i << " ";
        // cout << endl;
        // for(auto i : b) cout << i << " ";

        while(a.size() < b.size()) a.push_back(0);
        while(a.size() > b.size()) b.push_back(0);

        int i = 0, j = 0;
        
        while (i < a.size() && j < b.size()) {
            if(a[i] > b[j]){
                return 1;
            }
            else if(a[i] < b[j]){
                return -1;
            }
            i++, j++;
        }

        return 0;
    }
};