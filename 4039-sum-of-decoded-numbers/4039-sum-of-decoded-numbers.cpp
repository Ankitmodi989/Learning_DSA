class Solution {
public:
    long long modulo = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= modulo;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % modulo;
            base = (base * base) % modulo;
            exp /= 2;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long w = nums[i] % 10;
            long long d = nums[i] / 10;
            long long dis = 1;
            int count = 0;
            while ((d / dis) > 0) {
                dis = dis * 10;
                count++;
            }
            long long pro = 1;
            for (int j = 0; j < (count - w); j++) {
                pro *= 10;
            }
            long long x = d / pro;
            long long y = d % pro;

            cout << w << " " << d << " " << x << " " << y;
            sum = (sum + power(x, y)) % modulo;
        }
        return sum;
    }
};