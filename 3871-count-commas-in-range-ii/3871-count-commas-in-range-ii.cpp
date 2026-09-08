class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if (n < 1000) {
            return 0;
        }
        int count = 4;
        long long prev = 999;
        for (long long i = 1000; i <= n; i *= 10) {
            long long upper = min(n, i * 10 - 1);
            long long ele = upper - prev;
            long long rem = (count - 1) / 3;
            ans += (ele * rem);
            prev = upper;
            count++;
        }

        return ans;
    }
};