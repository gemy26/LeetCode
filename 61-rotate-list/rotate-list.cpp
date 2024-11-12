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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        ListNode* prev = head;
        ListNode *s;
        
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }

        if(k == 0 || len <= 1){
            return head;
        }

        k %= len;

         if(k == 0){
            return head;
        }
        cur = head;
        int cnt = len - k;
        while (cur != NULL && cnt--) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        ListNode* rotated_head = cur;
        while (rotated_head -> next != NULL) {
            rotated_head = rotated_head -> next;
        }

        rotated_head -> next = head;
        return  cur;
    }
};