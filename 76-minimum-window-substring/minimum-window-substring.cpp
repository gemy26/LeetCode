class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0 ,r = 0, ans = 1000000, ansl = 0, ansr = 0,have = 0;
   map<char,int>mps,mpt;
    for (int i = 0; i < t.size() ; ++i) {
        mpt[t[i]]++;
    }
    while(r < s.size() && l < s.size()){
        mps[s[r]]++;
       if(mpt.find(s[r])!=mpt.end() &&  mpt[s[r]] >= mps[s[r]]){
           have++;
       }
       if(have == t.size()){
           while(r > l){
//               cout << "here\n";
               if(mpt[s[l]] < mps[s[l]])
                   mps[s[l]]--,l++;
               else
                   break;
           }
           if(ans >= r - l + 1){
               ans = r - l + 1;
               ansl = l,ansr = r;
           }
       }


       r++;

    }
    string res= "";
    if(ans < 1000000)
        res =  s.substr(ansl,ans);
    return res;    
    }
};