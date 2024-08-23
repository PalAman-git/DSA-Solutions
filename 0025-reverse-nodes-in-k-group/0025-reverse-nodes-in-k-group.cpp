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
    int getLength(ListNode* head , int k){
        int c = 0;
        while(head != NULL)
        {
            head = head -> next;
            c++;
        }
        return c;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL){
            return NULL;
        }

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        while(curr != NULL && count < k)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL)
        {
            if(getLength(next,k) >= k)
            head -> next = reverseKGroup(next,k);

            else
            head -> next = next;
        }

        return prev;
    }
};