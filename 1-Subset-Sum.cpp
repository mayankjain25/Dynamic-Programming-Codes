class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>>dp(arr.size()+1, vector<bool>(sum+1));
        
        for(int i=0;i<=sum;i++){
            dp[0][i] = false;
        }
        
        for(int i=0;i<=arr.size();i++){
            dp[i][0] = true;
        }
        
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[arr.size()][sum];
    }
};
