class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0, ans = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        while (j < n) {
            sum += nums[j];
            while (i < j && sum > goal) {
                sum -= nums[i];
                i++;
                count = 0;
            }

            if (sum == goal) {
                while (i < j && nums[i] == 0) {
                    count++;
                    i++;
                }
                ans = ans + 1 + count;
            }
            j++;
        }
        return ans;
    }
};