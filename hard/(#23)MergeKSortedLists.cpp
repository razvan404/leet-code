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
    class NodesComparator {
    public:
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        priority_queue<ListNode*, vector<ListNode*>, NodesComparator> pq;
        for (auto list : lists) {
            if (list != NULL) {
                pq.push(list);
            }
        }
        if (pq.empty()) {
            return NULL;
        }

        ListNode* eliminated = pq.top();
        ListNode* root = new ListNode(eliminated->val);
        pq.pop();
        eliminated = eliminated->next;
        if (eliminated != NULL) {
            pq.push(eliminated);
        }

        ListNode* current = root;

        while (!pq.empty()) {
            eliminated = pq.top();
            pq.pop();
            current->next = new ListNode(eliminated->val);
            current = current->next;
            eliminated = eliminated->next;
            if (eliminated != NULL) {
                pq.push(eliminated);
            }
        }
        return root;
    }
};