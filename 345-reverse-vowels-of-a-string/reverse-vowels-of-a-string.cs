public class Solution {
    public string ReverseVowels(string s) {
        string vowelString = "AEIOUaeiou";
        string result = "";
        int position = 0;
    
        List <char> vowels = new List <char> ();
        for(int i = 0; i < s.Length; i++){
            if(vowelString.Contains(s[i])){
                vowels.Add(s[i]);
            }
        }
        vowels.Reverse();
        for(int i = 0; i < s.Length; i++){
            if(vowelString.Contains(s[i])){
                result += vowels[position ++];
            }
            else{
                result += s[i];
            }
        }
        return result;
    }
}