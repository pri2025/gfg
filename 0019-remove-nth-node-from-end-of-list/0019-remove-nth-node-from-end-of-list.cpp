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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 1; int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp =head;
        while(cnt <len - n){
            temp = temp->next;
            cnt++;
        }
       
        ListNode* del = temp -> next;
        temp-> next= del->next;
        delete del;

        return head;


    }
};