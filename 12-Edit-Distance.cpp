class Solution {
public:
    int helper(string &word1, string &word2, int n, int m, vector<vector<int>>&dp){
        // if(n==0 and m==0) return 0;
        if(m==0) return n;
        if(n==0) return m;
        if(dp[n][m]!=-1) return dp[n][m];

        if(word1[n-1]==word2[m-1]) return dp[n][m] = helper(word1, word2, n-1, m-1,dp);
        else{
            int insert = 0, deletes = 0, replace = 0;
            deletes = 1 + helper(word1, word2, n-1,m,dp);
            replace = 1 + helper(word1, word2,n-1,m-1,dp);
            insert = 1 + helper(word1, word2,n,m-1,dp);
            return dp[n][m] = min({insert, deletes, replace});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>prev(m+1,0),curr(m+1,0);
        
        // for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) prev[j] = j;

        for(int i=1;i<=n;i++){
            prev[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    int insert = 0, deletes = 0, replace = 0;
                    deletes = 1 +  prev[j];
                    replace = 1 + prev[j-1];
                    insert = 1 + curr[j-1];
                    curr[j] = min({insert, deletes, replace});
                }
            }
            prev=curr;
        }

        // if(n==0 and m==0) return 0;

        return prev[m];
    }
};
