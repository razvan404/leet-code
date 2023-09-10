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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* crt = head, *prev, *next;
        while (crt != NULL) {
            next = crt->next;
            crt->next = prev;
            prev = crt;
            crt = next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {    
        if (head == NULL || head->next == NULL || left == right) {
            return head;
        }
        bool isHead = left == 1;
        int idx = 1;
        ListNode* crt = head, *prev = NULL;
        ListNode* beforeStart, *start, *afterEnd;
        while (crt != NULL) {
            if (idx == left) {
                beforeStart = prev;
                start = crt;
            }
            if (idx == right) {
                afterEnd = crt->next;
                crt->next = NULL;
                break;
            }
            prev = crt;
            crt = crt->next;
            ++idx;
        }
        ListNode* ans = reverse(start);
        start->next = afterEnd;
        if (!isHead) {
            beforeStart->next = ans;
        } else {
            head = ans;
        }
        return head;
    }
};