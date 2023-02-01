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
    bool isPalindromeHelper(ListNode** head, ListNode* back) {
        if (*head == NULL) {
            return true;
        }
        if (back->next != NULL) {
            if (isPalindromeHelper(head, back->next) == false) {
                return false;
            }
        }
        if ((*head)->val != back->val) {
            return false;
        }
        *head = (*head)->next;
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        return isPalindromeHelper(&head, head);
    }
};