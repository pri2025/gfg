/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* del = node;
        ListNode* nextn = node;
        nextn = del -> next;

        del->val = nextn->val;
        del -> next = nextn->next;
    }
};