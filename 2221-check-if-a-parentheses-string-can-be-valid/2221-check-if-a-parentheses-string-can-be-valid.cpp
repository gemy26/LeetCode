class Solution {
public:
 bool canBeValid(string s, string locked) {
    if (s.size() & 1) {
        return false;
    }
    stack<int> already_open, can_change;
    for (int i = 0; i < s.size(); i++) {
        if (locked[i] == '0') {
            can_change.push(i);
        } else if (s[i] == '(') {
            already_open.push(i);
        } else {
            if (!already_open.empty()) {
                already_open.pop();
            } else if (!can_change.empty()) {
                can_change.pop();
            }else{
                return false;
            }
        }
    }
    while (!already_open.empty() && !can_change.empty() && already_open.top() < can_change.top()) {
        can_change.pop();
        already_open.pop();
    }
    if (!already_open.empty()) {
        return false;
    }
    return true;
}
};