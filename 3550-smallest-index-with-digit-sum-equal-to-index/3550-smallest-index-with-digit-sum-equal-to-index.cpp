class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            while (nums[i] > 0) {
                int rem = nums[i] % 10;
                sum += rem;
                nums[i] = nums[i] / 10;
            }
            if (sum == i) {
                mini = min(mini, i);
            }
        }
        if (mini != INT_MAX)
            return mini;
        else
            return -1;
    }
};