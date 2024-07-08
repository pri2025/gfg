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

    ListNode* revr(ListNode* node){
        ListNode* curr = node;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev; //last node
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow-> next;
            fast = fast->next->next;
        }
        //sending middle
        ListNode* sec_head = revr(slow); 
        // now list broken into two parts;
        
        while(sec_head != NULL){
            if(head->val != sec_head->val){
                return false;
            }
            head = head->next;
            sec_head = sec_head->next;
        }
        return true;
        
    }
};