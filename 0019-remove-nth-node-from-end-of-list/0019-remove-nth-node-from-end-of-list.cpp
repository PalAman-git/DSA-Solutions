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
    int length(ListNode* head)
    {
        if(head == NULL) return 0;
        ListNode* curr = head;
        int cnt = 0;
        while(curr != NULL) {
            curr = curr -> next;
            cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(length(head) == n) return head -> next;
        int nodeFromStart = length(head) - n;

        int cnt = 0;
        ListNode* curr = head;
        while(cnt != nodeFromStart - 1){
            curr = curr -> next;
            cnt++;
        }

        ListNode* nodeToDelete = curr -> next;
        curr -> next = nodeToDelete -> next;

        delete nodeToDelete;
        return head;
    }
};