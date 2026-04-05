class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector <string> ans;
        int i = 0;
        while (i < n) {
            int j = i;
            int lineLength = 0, totalChars = 0;
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                totalChars += words[j].size();
                j++;
            }
            int spaces = maxWidth - totalChars;
            int freeGaps = j - i - 1;
            string line = "";
            if (j == n || freeGaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }
                while (line.size() < maxWidth)
                    line += " ";
            } else {
                int spaceSize = spaces / freeGaps;
                int extraSpace = spaces % freeGaps;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1){
                        int add = spaceSize + (extraSpace > 0 ? 1 : 0);
                        line += string(add, ' ');
                        if(extraSpace > 0) extraSpace --;
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};