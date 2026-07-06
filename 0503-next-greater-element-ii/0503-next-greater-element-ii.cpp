class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> str;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!str.empty() && nums[str.top()] <= nums[idx]) {
                str.pop();
            }

            if (i < n) {
                if (!str.empty()) {
                    ans[idx] = nums[str.top()];
                }
            }
            str.push(idx);
        }
        return ans;
    }
};