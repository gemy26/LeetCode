class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for(int i = 0; i < n; i ++){
            while(!st.empty() && v[st.top()] >= v[i]){
                // 1 5 6 7 2
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i --){
            while(!st.empty() && v[st.top()] >= v[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i ++){
            ans = max(ans, (right[i] - left[i] - 1) * v[i]);
        }
        return ans;
    }
};