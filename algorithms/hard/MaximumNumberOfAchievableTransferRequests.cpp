class Solution {
private:
    void backtracking(vector<vector<int>>& requests, vector<int>& degrees, unsigned currentIdx, int currentNumOfRequests, int& maxNumOfRequests) {
        if (currentIdx == requests.size()) {
            for (const auto& degree : degrees) {
                if (degree != 0) {
                    return;
                }
            }
            if (currentNumOfRequests > maxNumOfRequests) {
                maxNumOfRequests = currentNumOfRequests;
            }
            return;
        }
        degrees[requests[currentIdx][0]]++;
        degrees[requests[currentIdx][1]]--;
        backtracking(requests, degrees, currentIdx + 1, currentNumOfRequests + 1, maxNumOfRequests);

        degrees[requests[currentIdx][0]]--;
        degrees[requests[currentIdx][1]]++;
        backtracking(requests, degrees, currentIdx + 1, currentNumOfRequests, maxNumOfRequests);
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> degrees(n);
        int maxNumOfRequests = 0;
        backtracking(requests, degrees, 0, 0, maxNumOfRequests);
        return maxNumOfRequests;  
    }
};