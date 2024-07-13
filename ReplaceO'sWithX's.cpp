class Solution{
public:
    void dfs(int row,int col,vector<vector<int>>&v,vector<vector<char>> &mat,
                                int delrow[],int delcol[]){
        v[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&
            v[nrow][ncol]==0&&mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,v,mat,delrow,delcol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && v[0][i]==0){
                dfs(0,i,v,mat,delrow,delcol);
            }
            if(mat[n-1][i]=='O' && v[n-1][i]==0){
                dfs(n-1,i,v,mat,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && v[i][0]==0){
                dfs(i,0,v,mat,delrow,delcol);
            }
            if(mat[i][m-1]=='O' && v[i][m-1]==0){
                dfs(i,m-1,v,mat,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'&&!v[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};