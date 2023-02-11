class Solution {
    enum Color { NIL, RED, BLUE };
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, Color>>> adjList(n);

        for (auto& edge : redEdges) {
            adjList[edge[0]].push_back({ edge[1], RED });
        }
        for (auto& edge : blueEdges) {
            adjList[edge[0]].push_back({ edge[1], BLUE });
        }
        map<pair<int, Color>, bool> visited;
        vector<int> ans(n, -1);
        queue<pair<int, Color>> queue;
        int currentLevel = 0;

        queue.push({ 0, NIL });
        visited[{ 0, NIL }] = true;
        ans[0] = currentLevel;

        while (!queue.empty()) {
            int size = queue.size();
            currentLevel++;
            while (size) {
                pair<int, Color> current = queue.front();
                queue.pop();
                size--;

                for (auto& neighb : adjList[current.first]) {
                    if (neighb.second != current.second && !visited[neighb]) {
                        ans[neighb.first] = ans[neighb.first] == -1 ? currentLevel : ans[neighb.first];
                        visited[neighb] = true;
                        queue.push(neighb);
                    }
                }
            }
        }

        return ans;
    }
};