class Solution {
public:
    int helper(int index, int sum, vector<int>&coins, vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(index==0){
            if(sum%coins[index]!=0) return 0;
            return 1;
        }

        if(dp[index][sum]!=-1) return dp[index][sum];

        int notPick = helper(index - 1, sum, coins,dp);
        int pick = 0;
        if(coins[index]<=sum) pick = helper(index, sum - coins[index], coins,dp);

        return dp[index][sum] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        vector<int>prev(amount+1, 0), curr(amount+1,0);
        // for(int i=0;i<=n;i++) prev[0] = 1;
        for(int i=0;i<=amount;i++){
            if(i%coins[0]!=0) prev[i] = 0;
            else prev[i] = 1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notPick = prev[j];
                int pick = 0;
                if(coins[i]<=j) pick = curr[j-coins[i]];
                curr[j] = pick + notPick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};
