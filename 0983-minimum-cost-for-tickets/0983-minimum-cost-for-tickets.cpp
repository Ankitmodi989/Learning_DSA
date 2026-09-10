class Solution {
public:
    int n;
    vector<int> dp;
    long long ticket(int i, vector<int>& days, vector<int>& costs) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int mini = INT_MAX;

        int t1 = costs[0] + ticket(i + 1, days, costs);
        mini = min(mini, t1);

        int j = i + 1;
        while (j < n && days[j] < (days[i] + 7)) {
            j++;
        }
        int t2 = costs[1] + ticket(j, days, costs);
        mini = min(mini, t2);

        while (j < n && days[j] < (days[i] + 30)) {
            j++;
        }
        int t3 = costs[2] + ticket(j, days, costs);
        mini = min(mini, t3);
        dp[i] = mini;

        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.assign(n, -1);
        return ticket(0, days, costs);
    }
};