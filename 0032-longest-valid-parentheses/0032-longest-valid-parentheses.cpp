class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int ans1 = 0;

        int open = 0;
        int close = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                close++;
            }
            if (open == close) {
                ans1 = max(ans1, open + close);
            } else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                open++;
            } else {
                close++;
            }
            if (open == close) {
                ans1 = max(ans1, open + close);
            } else if (close < open) {
                open = 0;
                close = 0;
            }
        }
        return ans1;
    }
};