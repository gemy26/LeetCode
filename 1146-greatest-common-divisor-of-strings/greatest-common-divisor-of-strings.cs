public class Solution {
    public string GcdOfStrings(string str1, string str2) {
        int x = str1.Length;
        int y = str2.Length;
        int period = GCD(x, y);
        string res = "";
        for(int i = 0; i < period; i++) res += str1[i];
        if(str1 + str2 != str2 + str1) res = "";
        return res;
    }
    public int GCD(int a, int b){
        return Math.Abs(b == 0 ? a : GCD(b, a % b));
    }
}