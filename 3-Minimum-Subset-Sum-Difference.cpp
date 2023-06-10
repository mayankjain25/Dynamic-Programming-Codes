//{ Driver Code Starts

//Problem Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = accumulate(arr, arr+n, 0);
	    vector<vector<int>>dp(n+1, vector<int>(sum+1));
	    
	    for(int i=0;i<=sum;i++) dp[0][i] = 0;
	    for(int i=0;i<=n;i++) dp[i][0] = 1;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
	            }
	            else{
	                dp[i][j] = dp[i-1][j] ;
	            }
	        }
	    }
	    
	    vector<int>v;
	    
	    for(int i=0;i<=sum/2;i++){
	        if(dp[n][i]) v.push_back(i);
	    }
	    
	    int ans = INT_MAX;
	    
	    for(int i=0;i<v.size();i++){
	        ans = min(ans, sum - 2*v[i]);
	    }
	    
	    return ans;
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
