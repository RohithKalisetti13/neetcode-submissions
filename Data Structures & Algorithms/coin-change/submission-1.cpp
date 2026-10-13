class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1, amount+1);
        dp[0]=0;

        for(int i=1;i<=amount;i++){
            for(auto& coin : coins){
               
                int balance = i-coin;
                
                if(balance>=0){
                    dp[i]= min(dp[balance]+1, dp[i]);
                }

            }
        }
    if(dp[amount]== amount+1) return -1;
    return dp[amount];
    }
};
