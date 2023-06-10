//Memoization
#include <bits/stdc++.h>

int helper(vector<int> &arr, int i, int j, vector<vector<int>>&dp) {
  if (i == j)
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];

  int ans = 1e9;
  for (int k = i; k <= j - 1; k++){
      int temp = arr[i-1]*arr[k]*arr[j] + helper(arr, i,k,dp) + helper(arr,k+1,j,dp);
      ans = min(ans, temp);
  }

  return dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr,int N)
{
    // Write your code here.
    int i = 1, j = arr.size() - 1;
    vector<vector<int>>dp(N+1, vector<int>(N+1, 0));

    for(int i = N-1;i>=1;i--){
        for(int j=N-2;j>=0;j--){
            int ans = 1e9;
            for (int k = i; k <= j - 1; k++){
                int temp = arr[i-1]*arr[k]*arr[j] + helper(arr, i,k,dp) + helper(arr,k+1,j,dp);
                ans = min(ans, temp);
            }

            return dp[i][j] = ans;
        }
    }
    return helper(arr, i,j,dp);
}
