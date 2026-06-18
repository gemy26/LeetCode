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
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0, pos = 0;
        ListNode *curr = head;
        while(curr != NULL){
            curr = curr->next;
            len ++;
        }
        if(len <= 1){
            return NULL;
        }
        curr = head;
        // cout << len << endl;
        while(curr != NULL && pos < len / 2 - 1){
            curr = curr->next;
            pos ++;
        }
        // cout << len << " " << pos << endl;
        ListNode *nextNode = curr->next;
        if(pos + 1 >= len || pos + 2 >= len){
            nextNode = NULL;
        }
        else{
            nextNode = nextNode->next;
        }
        curr->next = nextNode;
        return head;        
    }
};