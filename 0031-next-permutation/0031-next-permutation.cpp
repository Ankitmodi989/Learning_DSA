class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int temp = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                temp = i - 1;
                break;
            }
        }
        if (temp != -1)
            for (int i = n - 1; i >= 0; i--) {
                if (nums[temp] < nums[i]) {
                    swap(nums[temp], nums[i]);
                    break;
                }
            }
        reverse(nums.begin() + temp + 1, nums.end());
    }
};