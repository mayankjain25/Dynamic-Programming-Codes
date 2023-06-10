//MEMOIZATION

class Solution {
public:
    int LCS(string x, string y, int n, int m,vector<vector<int>>&dp){
        if(n==0 or m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        if(x[n-1]==y[m-1]) return dp[n][m] =  1 + LCS(x,y, n-1, m-1,dp);

        return dp[n][m] = max(LCS(x,y,n-1,m,dp), LCS(x,y,n,m-1,dp));
    }
    int longestCommonSubsequence(string x, string y) {
        int n = x.size(), m = y.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return LCS(x,y,n,m,dp);
    }
};

//TABULATION

class Solution {
public:
    int LCS(string x, string y, int n, int m,vector<vector<int>>&dp){
        if(n==0 or m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        if(x[n-1]==y[m-1]) return dp[n][m] =  1 + LCS(x,y, n-1, m-1,dp);

        return dp[n][m] = max(LCS(x,y,n-1,m,dp), LCS(x,y,n,m-1,dp));
    }
    int longestCommonSubsequence(string x, string y) {
        int n = x.size(), m = y.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

//SPACE OPTIMIZATION

class Solution {
public:
    int LCS(string x, string y, int n, int m,vector<vector<int>>&dp){
        if(n==0 or m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        if(x[n-1]==y[m-1]) return dp[n][m] =  1 + LCS(x,y, n-1, m-1,dp);

        return dp[n][m] = max(LCS(x,y,n-1,m,dp), LCS(x,y,n,m-1,dp));
    }
    int longestCommonSubsequence(string x, string y) {
        int n = x.size(), m = y.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        vector<int>prev(m+1,0), curr(m+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]) curr[j] = 1 + prev[j-1];
                else{
                    curr[j] = max(curr[j], curr[j-1]);
                }
            }
            prev=curr;
        }
        return curr[m];
    }
};


