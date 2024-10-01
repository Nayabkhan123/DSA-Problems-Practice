// SIMPLE RECURSION
int f(int i,int j,vector<vector<int>>&mat){
    if(i==0&&j==0){
        return 1;
    }
    if(i<0||j<0) return 0;
    if(mat[i][j]==-1) return 0;
    int left=f(i,j-1,mat);
    int up=f(i-1,j,mat);
    return left+up;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return f(n-1,m-1,mat);
}
// MEMOIZATION
int f(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
    
    if(i==0&&j==0){
        return 1;
    }
    
    if(i<0||j<0) return 0;
    if(mat[i][j]==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int left=f(i,j-1,mat,dp);
    int up=f(i-1,j,mat,dp);
    return dp[i][j]=left+up;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return f(n-1,m-1,mat,dp);
}
//TABULATION 
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) dp[i][j]=0;
            else if(i==0&&j==0) dp[i][j]=1;
            else{
                int up=0;
                int left=0;
               if(i>0) up = dp[i-1][j];
               if(j>0) left = dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n-1][m-1];
}
// SPACE OPTIMIZATION
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) curr[j]=0;
            else if(i==0&&j==0) curr[j]=1;
            else{
                int up=0;
                int left=0;
               if(i>0) up = prev[j];
               if(j>0) left = curr[j-1];
                curr[j]=(up+left)%int(1e9+7);
            }
        }
        prev=curr;
    }
    return prev[m-1];
}