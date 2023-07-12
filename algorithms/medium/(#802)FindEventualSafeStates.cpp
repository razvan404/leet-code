class Solution {
private:
    void haveSafeNodeNeighb(int crt, vector<vector<int>>& graph, vector<bool>& isSafeNode, vector<bool>& visited) {
        visited.at(crt) = true;
        if (graph.at(crt).empty()) {
            isSafeNode.at(crt) = true;
            return;
        }
        for (const int& neighb : graph.at(crt)) {
            if (!visited.at(neighb)) {
                haveSafeNodeNeighb(neighb, graph, isSafeNode, visited);
            }
            if (!isSafeNode.at(neighb)) {
                return;
            }
        }
        isSafeNode.at(crt) = true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> isSafeNode(graph.size(), false);
        vector<bool> visited(graph.size(), false);
        for (int i = 0; i < graph.size(); ++i) {
            if (!visited.at(i)) {
                haveSafeNodeNeighb(i, graph, isSafeNode, visited);
            }
        }
        vector<int> safeNodes;
        for (int i = 0; i < graph.size(); ++i) {
            if (isSafeNode.at(i)) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};