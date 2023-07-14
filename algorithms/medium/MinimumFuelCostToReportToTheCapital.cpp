class Solution {
    long long dfs(vector<vector<int>>& adjList, int current, int prev, int& seats, long long& ans) {
        long long people = 1;
        for (auto& neighb : adjList[current]) {
            if (neighb == prev) {
                continue;
            }
            people += dfs(adjList, neighb, current, seats, ans);
        }
        ans += (people + seats - 1) / seats;
        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adjList(n);
        long long ans = 0;

        for (auto& road : roads) {
            adjList[road[0]].push_back(road[1]);
            adjList[road[1]].push_back(road[0]);
        }

        for (auto& neighb : adjList[0]) {
            dfs(adjList, neighb, 0, seats, ans);
        }

        return ans;
    }
};