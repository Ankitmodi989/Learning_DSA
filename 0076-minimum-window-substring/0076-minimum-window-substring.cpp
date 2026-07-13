class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n < m)
            return "";

        unordered_map<char, int> mp;
        bool flag = false;
        for (int i = 0; i < m; i++) {
            mp[t[i]]++;
        }
        int j = 0, i = 0;
        int counter = m;
        int min_len = INT_MAX;
        int start_idx = 0;

        while (j < n) {

            if (mp.count(s[j]) && mp[s[j]] > 0) {
                counter--;
            }
            mp[s[j]]--;
            while (i <= j && counter == 0) {
                flag = true;
                if (min_len > (j - i + 1)) {
                    min_len = j - i + 1;
                    start_idx = i;
                }
                mp[s[i]]++;
                if (mp.count(s[i]) && mp[s[i]] > 0) {
                    counter++;
                }
                i++;
            }

            j++;
        }
        if (flag) return s.substr(start_idx, min_len);
        return "";
    }
};