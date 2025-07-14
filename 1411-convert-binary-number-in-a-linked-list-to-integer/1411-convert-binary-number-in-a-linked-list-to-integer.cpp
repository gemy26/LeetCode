/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s = "";
        int ans = 0, val = 1;
        while(head != NULL){
            s +=  '0' + head->val;
            head = head->next;
        }
        reverse(s.begin(), s.end());
        for(auto i : s){
            ans += (i == '1' ? val : 0);
            val *= 2;
        }
        return ans;
    }
};