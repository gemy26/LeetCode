class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> Prefix(s.size() + 2, 0);
        for (int i = 0; i < shifts.size(); i++) {
            auto [start, end, dir] =
                make_tuple(shifts[i][0], shifts[i][1], shifts[i][2]);
            if (dir == 0) {
                Prefix[start]--;
                Prefix[end + 1]++;
            } else if (dir == 1) {
                Prefix[start]++;
                Prefix[end + 1]--;
            }
        }

        for (int i = 1; i < Prefix.size(); i++) {
            Prefix[i] += Prefix[i - 1];
            Prefix[i] %= 26;
        }

        for (int i = 0; i < s.size(); i++) {
            int curr_char = s[i] - 'a';
            curr_char += Prefix[i];
            curr_char %= 26;
            curr_char = (curr_char +  26) % 26;
            s[i] = char(curr_char + 'a');
        }

        return s;
    }
};