class Solution {
private:
    void helper(int current, int n, vector<int>& arr, vector<int>& team, vector<bool>& banned, vector<int>& smallestTeam) {
        if (current == (1 << n) - 1) {
            if (smallestTeam.empty() || team.size() < smallestTeam.size()) {
                smallestTeam = team;
            }
            return;
        }
        if (!smallestTeam.empty() && team.size() >= smallestTeam.size()) {
            return;
        }
        int firstZero = 0;
        while ((current >> firstZero) & 1 == 1) {
            firstZero++;
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (banned[i]) {
                continue;
            }
            if ((arr[i] >> firstZero) & 1 == 1) {
                team.push_back(i);
                helper(current | arr[i], n, arr, team, banned, smallestTeam);
                team.pop_back();
            }
        }
    }

public:
    vector<int> smallestSufficientTeam(vector<string>& reqSkills, vector<vector<string>>& people) {
        unordered_map<string, int> skillToIdx;
        for (int i = 0; i < reqSkills.size(); ++i) {
            skillToIdx[reqSkills[i]] = i;
        }
        vector<int> arr(people.size(), 0);
        for (int i = 0; i < people.size(); ++i) {
            for (const string& skill : people[i]) {
                arr[i] |= 1 << skillToIdx[skill];
            }
        }
        vector<bool> banned(people.size(), false);
        for (int i = 0; i < people.size() - 1; ++i) {
            for (int j = i + 1; j < people.size(); ++j) {
                int val = arr[i] | arr[j];
                if (val == arr[i]) {
                    banned[j] = true;
                } else if (val == arr[j]) {
                    banned[i] = true;
                }
            }
        }
        vector<int> smallestTeam;
        vector<int> team;
        helper(0, reqSkills.size(), arr, team, banned, smallestTeam);
        return smallestTeam;
    }
};

