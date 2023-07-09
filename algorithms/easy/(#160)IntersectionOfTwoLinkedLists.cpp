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
        ListNode* currA = headA, *currB = headB;
        int lenA = 0, lenB = 0, len;
        while (currA) {
            lenA++;
            currA = currA->next;
        }
        while (currB) {
            lenB++;
            currB = currB->next;
        }
        len = min(lenA, lenB);
        currA = headA;
        currB = headB;
        while (lenA > len) {
            currA = currA->next;
            lenA--;
        }
        while (lenB > len) {
            currB = currB->next;
            lenB--;
        }
        while (currA) {
            if (currA == currB) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};