#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelDays(days.begin(), days.end());
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);

        //hnn aa jao dekh lo kese solve kiya h mene

        for (int i = 1; i <= lastDay; i++) {
            if (travelDays.find(i) == travelDays.end()) {
                dp[i] = dp[i - 1];
                continue;
            }

            int pass1 = dp[i - 1] + costs[0];
            int pass7 = dp[max(0, i - 7)] + costs[1];
            int pass30 = dp[max(0, i - 30)] + costs[2];

            dp[i] = min({pass1, pass7, pass30});
        }

        return dp[lastDay];
    }
};