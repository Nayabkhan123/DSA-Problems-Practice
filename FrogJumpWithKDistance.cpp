int f(int ind,int k,vector<int>&heights,vector<int>&dp){
    if(ind==0) return 0;
    int steps=INT_MAX;
    if(dp[ind]!=-1) return dp[ind];
    for(int j=1;j<=k;j++){ 
        if(ind-j>=0) {
        int jump=f((ind-j),k,dp)+abs(heights[ind]-heights[ind-j]);
        steps=min(steps,jump);
        }
    }
    return dp[ind]=steps;
}
int frog(int n,int k vector<int> &heights){
    vector<int>dp(n,-1);
    return f(n-1,k,heights,dp);

}