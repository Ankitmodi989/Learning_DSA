class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 0;
        int count = 0;

        while (j < n) {
            mp[nums[j]]++;
            while (mp.size() > k) {
                mp[nums[i]]--;

                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                count = 0;
                i++;
            }
            if (mp.size() == k) {
                while (mp[nums[i]] > 1) {
                    mp[nums[i]]--;
                    count++;
                    i++;
                }
                ans = ans + count + 1;
            }
            j++;
        }
        return ans;
    }
};