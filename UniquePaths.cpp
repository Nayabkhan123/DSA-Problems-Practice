#include <bits/stdc++.h> 
int f(int i,int j){
	if(i==0&&j==0) {
		return 1;
	}
	if(i<0 || j<0) return 0;
	int down=f(i-1,j);
	// if(col+1<=n)
	int right=f(i,j-1);
	return down+right;
}
int uniquePaths(int m, int n) {
	return f(m-1,n-1);
}

//tabulation method
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0&&j==0) dp[i][j]=1;
			else{
				int up=0;
				int left=0;
				if(i>0) up=dp[i-1][j];
				if(j>0) left=dp[i][j-1];
				dp[i][j]=up+left;
			}
		}
	}
	return dp[m-1][n-1];
	}


// MEMOIZATION METHOD


    int f(int i,int j,vector<vector<int>>dp){
	if(i==0&&j==0) {
		return 1;
	}
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int down=f(i-1,j,dp);
	// if(col+1<=n)
	int right=f(i,j-1,dp);
	return dp[i][j]=down+right;
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return f(m-1,n-1,dp);
}