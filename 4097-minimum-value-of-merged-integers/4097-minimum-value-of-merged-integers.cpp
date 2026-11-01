class Solution {
public:
    int minMergedInteger(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i += 2) {
            string s1 = to_string(nums[i]);
            string s2 = to_string(nums[i + 1]);
            string s3 = s1 + s2;
            int n1 = stoi(s3);
            ans = min(ans, n1);
        }
        return ans;
    }
};