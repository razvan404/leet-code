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
    ListNode* reverseList(ListNode* head, ListNode* nextLink, int k) {
        ListNode* current = head->next, *prev, *next = current->next;

        head->next = nextLink;
        current->next = head;
        prev = current;
        current = next;
        k -= 2;
        
        while (k > 0 && current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            k--;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) {
            return head;
        }

        ListNode* current = head;
        int q = k - 1;
        while (q && current != NULL) {
            current = current->next;
            q--;
        }
        if (current == NULL) {
            return head;
        }
        ListNode* prev = head;
        head = reverseList(head, current->next, k);
        current = prev->next;

        while (true) {
            q = k - 1;
            ListNode* temp = current;
            while (q && current != NULL) {
                current = current->next;
                q--;
            }
            if (current == NULL) {
                break;
            }
            ListNode* oldTemp = temp;
            prev->next = reverseList(temp, current->next, k);
            prev = oldTemp;
            current = prev->next;
        }

        return head;
    }
};