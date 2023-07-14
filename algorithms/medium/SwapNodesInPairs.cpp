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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* current = head->next, *prev;

        head->next = head->next->next;
        current->next = head;
        head = current;
       
        prev = current->next;
        current = current->next->next;

        while (current != NULL) {
            if (current->next == NULL) {
                break;
            }
            ListNode* temp = current->next, *next = current->next->next;
            prev->next = temp;
            current->next = next;
            temp->next = current;

            prev = current;
            current = next;
        }

        return head;
    }
};