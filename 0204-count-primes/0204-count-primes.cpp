class Solution {
public:
    int countPrimes(int n) {

        vector<bool> temp(n+1, true);
        temp[0] = false, temp[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (temp[i] == true) {
                for (int j = 2; j*i < n; j++) {
                    temp[i * j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i])
                count++;
        }
        return count;
    }
};