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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* initL1 = l1;
        int f = 0;
        ListNode* antL1 = NULL;
        while (l1 != NULL && l2 != NULL) {
            int newf = (l1->val + l2->val + f) / 10;
            l1->val = (l1->val + l2->val + f) % 10;
            f = newf;

            antL1 = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2 != NULL) {
            if (antL1) {
                antL1->next = l2;
            }
            l1 = l2;
        }

        while (l1 != NULL) {
            int newf = (l1->val + f) / 10;
            l1->val = (l1->val + f) % 10;
            f = newf;

            antL1 = l1;
            l1 = l1->next;
        }

        if (f) {
            antL1->next = new ListNode(f);
        }

        return initL1;
    }
};