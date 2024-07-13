class Solution {
  public:
  void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &v){
      v[row][col]=1;
      int n=grid.size();
      int m=grid[0].size();
      int delrow[] = {-1,0,1,0};
      int delcol[] = {0,1,0,-1};
      for(int i=0;i<4;i++){
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if(ncol>=0&&nrow>=0&&ncol<m&&nrow<n && !v[nrow][ncol]){
              if(grid[nrow][ncol]==1 ){
                v[nrow][ncol]=1;
                dfs(nrow,ncol,grid,v);
              }
          }
          
      }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || j==m-1 || i==n-1){
                if(!v[i][j]&&grid[i][j]==1){
                    dfs(i,j,grid,v);
                }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0&&grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};