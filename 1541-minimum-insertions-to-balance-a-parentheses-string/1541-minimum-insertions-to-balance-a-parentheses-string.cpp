class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        int balance = 0;
        int count = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                balance++;
                i++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    count++;
                    i += 1;
                }

                if (balance == 0) {
                    count++;
                } else {
                    balance--;
                }
            }
        }

        if (balance > 0) {
            count = count + 2 * abs(balance);
        }

        return count;
    }
};