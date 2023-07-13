class Solution {
private:
    bool haveCycle(int crt, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& couldFinish) {
        visited.at(crt) = true;
        for (const auto& neighb : adj.at(crt)) {
            if (visited.at(neighb) && !couldFinish.at(neighb)) {
                return true;
            } else if (!visited.at(neighb)) {
                if (haveCycle(neighb, adj, visited, couldFinish)) {
                    return true;
                }
            }
        }
        couldFinish.at(crt) = true;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> couldFinish(numCourses, false);
        vector<bool> visited(numCourses, false);
        for (const auto& prerequisite : prerequisites) {
            adj.at(prerequisite.at(1)).push_back(prerequisite.at(0));
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!visited.at(i)) {
                if (haveCycle(i, adj, visited, couldFinish)) {
                    return false;
                }
            }
        }
        return true;
    }
};
