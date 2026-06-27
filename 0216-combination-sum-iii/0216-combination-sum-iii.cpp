class Solution {
public:
    vector<vector<int>> ans;
    bool isSafe(int num, int tar) {
        return num <= tar;
    }
    void combination(int i, int start, vector<int>& track, int target, int k) {
        if (i == k) {
            if (target == 0) {
                ans.push_back(track);
            }
            return;
        }
        for (int l = start; l <= 9; l++) {
            if (isSafe(l, target)) {
                track[i] = l;
                combination(i + 1, l + 1, track, target - l, k);
                track[i] = 0;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track(k, 0);
        combination(0, 1, track, n, k);
        return ans;
    }
};