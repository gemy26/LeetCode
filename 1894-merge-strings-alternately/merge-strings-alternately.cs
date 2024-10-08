public class Solution {
    public string MergeAlternately(string word1, string word2) {
        string res = "";
        for(int i = 0; i < Math.Max(word1.Length , word2.Length); i++){
            if(i < word1.Length) res += word1[i];
            if(i < word2.Length) res += word2[i];
        }
        return res;
    }
}