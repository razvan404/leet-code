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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (k == 1) return { head };
        vector<ListNode*> parts(k, NULL);
        
        int len = 0;
        ListNode* current = head, *prev = NULL;
        while (current) {
            ++len;
            current = current->next;
        }
        int minSize = len / k, extra = len % k;
        current = head;
        for (int i = 0; current && i < k; ++i, --extra) {
            parts[i] = current;
            for (int j = 0; j < minSize + (extra > 0); ++j) {
                prev = current;
                current = current->next;
            }
            prev->next = NULL;
        }
        return parts;
    }
};