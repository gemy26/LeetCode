class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = to_string(num);
        for (auto i : s) {
            if (i != '9') {
                for (auto& j : s) {
                    if (j == i) {
                        j = '9';
                    }
                }
                break;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (i == 0) {
                if (t[i] != '1') {
                    auto dig = t[i];
                    for (auto& j : t) {
                        if (j == dig) {
                            j = '1';
                        }
                    }
                    break;
                }
            } else {
                if (t[i] != '0' && t[i] != t[0]) {
                    auto dig = t[i];
                    for (auto& j : t) {
                        if (j == dig) {
                            j = '0';
                        }
                    }
                    break;
                }
            }
        }

        int a = stoi(s), b = stoi(t);
        return a - b;
    }
};