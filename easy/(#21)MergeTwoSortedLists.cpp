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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root, *current;
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        if (list1->val < list2->val) {
            root = list1;
            list1 = list1->next;
        }
        else {
            root = list2;
            list2 = list2->next;
        }
        current = root;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
                current = current->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
                current = current->next;
            }
        }

        if (list1 != NULL) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        return root;
    }
};