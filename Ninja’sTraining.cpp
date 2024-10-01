// using recursion (Gives TLE)
int f(int days,int last,vector<vector<int>> &points){
    if(days==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(last!=i){
                maxi=max(maxi,points[0][i]);
            }
           
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(last!=i){
            int point=points[days][i]+f(days-1,i,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    
    return f(n-1,3,points);
}

//using dp

int f(int days,int last,vector<vector<int>> &points,vector<vector<int>>&dp){
    if(days==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(last!=i){
                maxi=max(maxi,points[0][i]);
            }
           
        }
        return maxi;
    }
    if(dp[days][last]!=-1) return dp[days][last];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(last!=i){
            int point=points[days][i]+f(days-1,i,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[days][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}
//TABULATION

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,0));
    for(int i=0;i<3;i++){
        dp[0][i]=max(points[0][(i+1)%3],points[0][(i+2)%3]);
    }
    // dp[0][3]=max(max(points[0][0],points[0][1]),points[0][2]);
    for(int days=1;days<n;days++){
        for(int last=0;last<4;last++){
            dp[days][last]=0;
            for(int k=0;k<3;k++){
                if(last!=k){
                    int point=points[days][k]+dp[days-1][k];
                    dp[days][last]=max(dp[days][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
//space optimization

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>dp(4,0);
    for(int i=0;i<3;i++){
        dp[i]=max(points[0][(i+1)%3],points[0][(i+2)%3]);
    }
    // dp[0][3]=max(max(points[0][0],points[0][1]),points[0][2]);
    for(int days=1;days<n;days++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            
            temp[last]=0;
            for(int k=0;k<3;k++){
                if(last!=k){
                    int point=points[days][k]+dp[k];
                    temp[last]=max(temp[last],point);
                }
            }
        }
        dp=temp;
    }
    return dp[3];
}