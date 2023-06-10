#include<bits/stdc++.h>
using namespace std;

int main(){
	string x,y;
	cin>>x>>y;
	
	int n = x.size();
	int m = y.size();
	
	vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i-1]==y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	for(auto it:dp){
		for(auto it1:it) cout<<it1<<" ";
			cout<<endl;
	}
	
	int lcsLength = dp[n][m];
	// cout<<lcsLength;
	string ans="";
	for(int i=0;i<lcsLength;i++) ans.push_back('$');
	// cout<<ans<<endl;
	lcsLength--;
		
	int i =n, j = m;
	while(i>0 and j>0){
		if(x[i-1]==y[j-1]){
			ans[lcsLength--] = x[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i = i-1;
			
		}
		else j=j-1;
	}
	
	cout<<ans<<endl;
}
