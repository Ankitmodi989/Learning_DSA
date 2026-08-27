class Solution {
public:

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n / 2;
        int n2 = n - n1;

        vector<long long> sumA;
        for (int mask = 0; mask < (1 << n1); mask++) {
            long long sum = 0;
            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }
            sumA.push_back(sum);
        }

        vector<long long> sumB;
        for (int mask = 0; mask < (1 << n2); mask++) {
            long long sum = 0;
            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i + n1 ];
                }
            }
              sumB.push_back(sum);
        }

        sort(sumB.begin(), sumB.end());

        long long mini = INT_MAX;
        for (long long sum1 : sumA) {
            long long need = goal - sum1;
            auto it = lower_bound(begin(sumB), end(sumB), need);

            if (it != sumB.end()) {
                mini = min(mini, abs(sum1 + *it - goal));
            }
            
            if (it != sumB.begin()) {
                mini = min(mini, abs(sum1 + *prev(it) - goal));
            }
        }
        return mini;
    }
};