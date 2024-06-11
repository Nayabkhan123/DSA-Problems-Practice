void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int row,int col,vector<vector<int>>&v,
            int iniColor) {
                
                
            v[sr][sc]=1;
            image[sr][sc]=newColor;
            
            if((sr-1)>=0&&!v[sr-1][sc]&&image[sr-1][sc]==iniColor){
                dfs(image,sr-1,sc,newColor,row,col,v,iniColor);
            }
            if((sc+1)<col&&!v[sr][sc+1]&&image[sr][sc+1]==iniColor){
                dfs(image,sr,sc+1,newColor,row,col,v,iniColor);
            }
            if((sr+1)<row&&!v[sr+1][sc]&&image[sr+1][sc]==iniColor){
                dfs(image,sr+1,sc,newColor,row,col,v,iniColor);
            }
            if((sc-1)>=0&&!v[sr][sc-1]&&image[sr][sc-1]==iniColor){
                dfs(image,sr,sc-1,newColor,row,col,v,iniColor);
            }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        int iniColor = image[sr][sc];
        vector<vector<int>>v(row, vector<int> (col, 0));
        
        dfs(image,sr,sc,newColor,row,col,v,iniColor);
        return image;
    }