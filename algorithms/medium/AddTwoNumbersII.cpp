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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* crt = head, *prev = NULL, *next;
        while (crt) {
            next = crt->next;
            crt->next = prev;
            prev = crt;
            crt = next;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* head = new ListNode(0), *tail = head;
        int carry = 0, digit1, digit2;
        while (l1 != nullptr ||  l2 != nullptr || carry != 0) {
            digit1 = (l1 != nullptr) ? l1->val : 0;
            digit2 = (l2 != nullptr) ? l2->val : 0;
            int digit = digit1 + digit2 + carry;
            carry = digit / 10;
            digit = digit % 10;

            ListNode* node = new ListNode(digit);
            tail->next = node;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* result = head->next;
        delete head;
        return reverseList(result);
    }
};
