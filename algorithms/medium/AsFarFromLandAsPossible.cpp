class Solution {
    pair<int, int> directions[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> qp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    qp.push({ i, j });
                }
            }
        }
        int iterations = 0;

        if (qp.empty() || qp.size() == n * n) {
            return -1;
        }

        while (!qp.empty()) {
            int size = qp.size();
            while (size) {
                pair<int, int> current = qp.front();
                qp.pop();
                size--;

                for (auto direction : directions) {
                    int x = current.first + direction.first, y = current.second + direction.second;
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        qp.push({ x, y });
                    }
                }
            }
            iterations++;
        }

        return iterations - 1;
    }
};