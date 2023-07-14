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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        head = prev;
        ListNode* current = head;
        while (current->next != NULL) {
            if (current->next->next != NULL && current->next->val == current->next->next->val) {
                while (current->next->next != NULL && current->next->val == current->next->next->val) {
                    tmp = current->next->next;
                    current->next->next = current->next->next->next;
                    delete tmp;
                }
                tmp = current->next;
                current->next = current->next->next;
                delete tmp;
            }
            else {
                current = current->next;
            }
        }
        return head->next;
    }
};