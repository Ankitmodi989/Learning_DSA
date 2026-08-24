class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            num ^= nums[i];
        }

        while (num) {
            if (num & 1) {
                break;
            }
            count++;
            num >>= 1;
        }
        int ele1 = 0;
        int ele2 = 0;
        for (int i = 0; i < n; i++) {
            int ele = nums[i] >> count;
            if (ele & 1) {
                ele1 ^= nums[i];
            } else {
                ele2 ^= nums[i];
            }
        }
        return {ele1, ele2};
    }
};