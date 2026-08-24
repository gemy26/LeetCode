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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* modify = head->next;
        ListNode* curr = modify;

        while(curr) {
            sum = 0;
            while(curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }
            modify->val = sum;
            curr = curr->next;
            modify->next = curr;
            modify = modify->next;
        }

        return head->next;
    }
};