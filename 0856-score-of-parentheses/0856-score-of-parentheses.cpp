class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, cnt = 0;
        stack <int> st;
        st.push(0);

        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(') {
               st.push(0);
            } else{
                int inside = st.top();
                st.pop();

                if(inside == 0) {
                    int below = st.top();
                    st.pop();
                    st.push(below + 1);
                } else{
                    int below = st.top();
                    st.pop();
                    st.push(below + 2 * inside);
                }
            }
        }
        return st.top();
    }
};