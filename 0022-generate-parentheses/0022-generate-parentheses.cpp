class Solution {
public:
    vector<string> ans;

    void parenthesis(int n, int open, int close, string s) {
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            s.push_back('(');
            parenthesis(n, open + 1, close, s);
            s.pop_back();
        }
        

        if (open > close && close<n) {
            s.push_back(')');
            parenthesis(n, open, close + 1, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string s = "";
        parenthesis(n, open, close, s);
        return ans;
    }
};