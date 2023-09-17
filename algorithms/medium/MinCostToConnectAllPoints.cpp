class Solution {
private:
    inline int distance(vector<int>& P, vector<int>& Q) {
        return abs(P[0] - Q[0]) + abs(P[1] - Q[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int n = points.size(), minCost = 0;
        vector<bool> visited(n, false);
        vector<int> cache(n, INT_MAX);
        minHeap.push({0, 0});
        while (!minHeap.empty()) {
            auto edge = minHeap.top();
            minHeap.pop();
            int cost = edge.first;
            int u = edge.second;

            if (visited[u]) continue;
            visited[u] = true;
            minCost += cost;
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = distance(points[u], points[v]);
                    if (dist < cache[v]) {
                        cache[v] = dist;
                        minHeap.push({dist, v});
                    }
                }
            }
        };
        return minCost;
    }
};
