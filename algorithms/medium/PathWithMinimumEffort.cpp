class Solution {
private:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    inline bool isValid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({0, 0, 0});
        dist[0][0] = 0;

        while (!minHeap.empty()) {
            auto [cost, x, y] = minHeap.top();
            minHeap.pop();

            if (cost > dist[x][y]) continue;
            if (x == rows - 1 && y == cols - 1) return cost;
            for (const auto& dir: directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (isValid(nx, ny, rows, cols)) {
                    int newCost = max(cost, abs(heights[x][y] - heights[nx][ny]));
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        minHeap.push({newCost, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};
