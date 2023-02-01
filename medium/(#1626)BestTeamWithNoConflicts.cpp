class Solution {
    struct Player {
        int age;
        int score;
        bool operator<(const Player& oth) const {
            if (age < oth.age) {
                return true;
            }
            return age == oth.age && score < oth.score;
        }
    };
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int n = scores.size();
        vector<int> dp(n);
        vector<Player> players;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            players.push_back({ ages[i], scores[i] });
        }
        sort(players.begin(), players.end());
        for (int i = 0; i < n; ++i) {
            dp.at(i) = players.at(i).score;
            for (int j = i - 1; j > -1; --j) {
                if (players.at(i).score >= players.at(j).score) {
                    dp.at(i) = max(dp.at(i), dp.at(j) + players.at(i).score);
                }
            }
            ans = max(ans, dp.at(i));
        }
        return ans;
    }
};