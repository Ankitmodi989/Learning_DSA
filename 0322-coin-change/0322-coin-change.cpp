// class Solution {
// public:
//     int coin(vector<int>&coins,int amount,int n){
//         if( amount == 0){
//             return 0;
//         }
//         if(n<0 || amount<0) return 1e9;
      

//         int take  = 1e9;
//         if(amount >=  coins[n]){
//             take = 1 + coin(coins,amount-coins[n],n);
//         }
//         int skip = coin(coins,amount,n-1);

//         return min(take,skip);

//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         return coin(coins,amount,n-1)==1e9?-1:coin(coins,amount,n-1);
//     }
// };



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);
        
        dp[0] = 0; 

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                 
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};

