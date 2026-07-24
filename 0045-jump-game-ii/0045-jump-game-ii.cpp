class Solution {
public:
    int jumping(int i, vector<int>& nums,  int n,vector<int>&dp) {
        if (i == n - 1) {
            return 0;
        }
        if(i >= n){
            return 1e9;
        }
         if (dp[i] != -1)
            return dp[i];

        int minJumps = 1e9;

        for (int j = 1; j <= nums[i]; j++) {
            int take = jumping(i + j, nums, n,dp);
            if(take != 1e9)
            minJumps = min(minJumps, take + 1);
        }
        return dp[i] =minJumps;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n,-1);

       return jumping(0, nums, n,dp);
        
    }
};