class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        unordered_map<int, int> sizeStartIndex;
        for (int i = 0; i < groupSizes.size(); ++i) {
            if (!sizeStartIndex.count(groupSizes[i]) || groups[sizeStartIndex[groupSizes[i]]].size() == groupSizes[i]) {
                sizeStartIndex[groupSizes[i]] = groups.size();
                groups.push_back({ i });
            } else {
                groups[sizeStartIndex[groupSizes[i]]].push_back(i);
            }
        }
        return groups;
    }
};
