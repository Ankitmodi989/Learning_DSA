class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> arr(n, false);
        arr[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (arr[j]==true && j + nums[j] >= i) {
                    arr[i] = true;
                    break;
                }
            }
            if (arr[i]==false)
                return false;
        }
        return true;
    }
};