/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node* helper(Node* crt, map<Node*, Node*>& nodesMap) {
        if (crt == NULL) {
            nodesMap.insert({ NULL, NULL });
            return NULL;
        }
        Node* copyCrt = new Node(crt->val);
        nodesMap.insert({ crt, copyCrt });
        copyCrt->next = helper(crt->next, nodesMap);
        copyCrt->random = nodesMap.at(crt->random);
        return copyCrt;
    }
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> nodesMap;
        return helper(head, nodesMap);
    }
};
