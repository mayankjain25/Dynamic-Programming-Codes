class Solution {
public:
    int MOD = (int)(1e9);
    int helper(string s, string t, int n, int m, vector<vector<int>>&dp){
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        //two choices - pick or not pick
        int pick = 0, notPick =0;
        notPick =  helper(s,t,n-1,m,dp);
        if(s[n]==t[m]) {pick= helper(s,t,n-1,m-1,dp);}

        return dp[n][m] = pick + notPick;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1,0));

        vector<int>prev(m+1,0), curr(m+1,0);

        // for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++)
        {
            prev[0] = 1;
            for(int j=1;j<=m;j++){
                int notPick = prev[j];
                int pick = 0;
                if(s[i-1]==t[j-1]){
                    pick = prev[j-1];
                }

                curr[j] = (pick + notPick)%MOD;
            }
            prev=curr;
        }
        return prev[m];
    }
};
