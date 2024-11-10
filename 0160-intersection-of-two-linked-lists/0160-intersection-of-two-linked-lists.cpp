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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while(headB){
            ListNode* ptr = headA;
            while(ptr){
                if(ptr == headB) return headB;
                else{
                    ptr = ptr -> next;
                }
            }
            headB = headB -> next;
        }
        return NULL;
    }
};