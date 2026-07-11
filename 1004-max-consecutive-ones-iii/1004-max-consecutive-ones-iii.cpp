class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int l = k;
        int ans = 0;

        while (i <= j && j < n) {
            if (nums[j] == 1) {
                j++;
            } else if (nums[j] == 0 && l > 0) {
                j++;
                l--;
            } else {
                while(nums[i]!=0){
                    i++;
                }
                i++;
                j++;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};