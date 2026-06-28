class Solution {
public:
    bool isPalindrome(int left, int right, string s) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++, right--;
        }
        return true;
    }

    void palindrome(int idx, vector<string>& temp, string s, int n,
                    vector<vector<string>>& ans) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (isPalindrome(idx, i, s)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                palindrome(i + 1, temp, s, n, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.length();
        vector<string> temp;
        palindrome(0, temp, s, n, ans);
        return ans;
    }
};