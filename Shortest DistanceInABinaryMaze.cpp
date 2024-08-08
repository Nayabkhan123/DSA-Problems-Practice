class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source.first==destination.first
            && source.second==destination.second) return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        int sr=source.first;
        int sc=source.second;
        dis[sr][sc]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{sr,sc}});
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int cdis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];
                if(newr>=0&&newr<n&&newc>=0&&newc<m
                && grid[newr][newc] && (cdis+1<dis[newr][newc])){
                    dis[newr][newc]=cdis+1;
                    if(newr==destination.first&&newc==destination.second) return cdis+1;
                    q.push({cdis+1,{newr,newc}});
                }
            }
        }
        
        return -1;
    }
};