class Solution {
private:
    void topologicalSort(string& airport, unordered_map<string, vector<string>>& adjacencyLists, vector<string>& itinerary) {
        while (!adjacencyLists[airport].empty()) {
            string& nextAirport = adjacencyLists[airport].back();
            adjacencyLists[airport].pop_back();
            topologicalSort(nextAirport, adjacencyLists, itinerary);
        }
        itinerary.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjacencyLists;
        for (const auto& ticket : tickets) {
            adjacencyLists[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [_, destinations] : adjacencyLists) {
            sort(destinations.begin(), destinations.end(), greater<string>());
        }
        vector<string> itinerary;
        string start = "JFK";
        topologicalSort(start, adjacencyLists, itinerary);
        return {itinerary.rbegin(), itinerary.rend()};
    }
};