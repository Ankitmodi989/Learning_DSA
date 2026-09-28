class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                op++;
                ans = max(ans, op);
            }
            if(s[i] == ')' && op>0){
                op--;
            }
        }
        return ans;
    }
};