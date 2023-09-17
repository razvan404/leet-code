class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        unordered_set<int> visited;
        int all = (1 << n) - 1;
        for (int i = 0; i < n; ++i) {
            int maskValue = 1 << i;
            q.push({ i, maskValue, 1 });
            visited.insert(i << 12 | maskValue);
        }
        while (!q.empty()) {
            auto [node, mask, cost] = q.front();
            q.pop();
            if (mask == all) {
                return cost - 1;
            }
            for (const auto& adj : graph[node]) {
                int bothVisitedMask = mask | (1 << adj);
                if (!visited.count(adj << 12 | mask)) {
                    visited.insert(adj << 12 | mask);
                    q.push({ adj, bothVisitedMask, cost + 1 });
                }
            }
        }
        return -1;
    }
};
