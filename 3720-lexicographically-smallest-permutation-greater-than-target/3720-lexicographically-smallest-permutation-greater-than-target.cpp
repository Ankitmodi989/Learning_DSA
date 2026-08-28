class Solution {
public:
    int n;
    string permutation(int i, string& temp, string& target, vector<int>& alpa,
                       bool greater) {
        if (i == n) {
            return greater ? temp : "";
        }

        for (int j = 0; j < 26; j++) {
            if (alpa[j] > 0) {
                char ch = 'a' + j;

                if (!greater && ch < target[i]) {
                    continue;
                }
                alpa[j]--;
                temp.push_back(ch);

                bool next_greater = greater || (ch > target[i]);
                string res =
                    permutation(i + 1, temp, target, alpa, next_greater);

                if (!res.empty()) {
                    return res;
                }
                temp.pop_back();
                alpa[j]++;
            }
        }
        return "";
    }
    string lexGreaterPermutation(string s, string target) {
        n = s.length();

        vector<int> alpa(26, 0);
        for (char c : s) {
            alpa[c - 'a']++;
        }
        string temp = "";

        return permutation(0, temp, target, alpa, false);
    }
};