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
    int lenght(ListNode* head) {
        ListNode* ptr = head;
        int cnt = 0;
        while (ptr) {
            cnt++;
            ptr = ptr->next;
        }
        return cnt;
    }
    ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
        // while(headB){
        //     ListNode* ptr = headA;
        //     while(ptr){
        //         if(ptr == headB) return headB;
        //         else{
        //             ptr = ptr -> next;
        //         }
        //     }
        //     headB = headB -> next;
        // }
        // return NULL;
        int l1 = lenght(head1);
        int l2 = lenght(head2);
        int diff = abs(l1 - l2);

        if (l1 > l2) {
            for (int i = 0; i < diff; i++) {
                head1 = head1->next;
            }
        } else {
            for (int i = 0; i < diff; i++) {
                head2 = head2->next;
            }
        }

        while (head1 && head2) {
            if (head1 == head2)
                return head1;
            else {
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return NULL;
    }
};