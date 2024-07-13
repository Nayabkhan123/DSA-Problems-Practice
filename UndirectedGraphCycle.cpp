
// using bfs algo
 bool iscycle(int src, vector<int> adj[],int v[]){
      v[src]=1;
      queue<pair<int,int>>q;
      q.push({src,-1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto i:adj[node]){
              if(!v[i]){
                  v[i]=1;
                  q.push({i,node});
              }
              else if(parent != i){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int v[V] = {0};
        for(int i=0;i<V;i++){
            if(!v[i]){
                if(iscycle(i,adj,v)){
                    return true;
                };
            }
        }
        return false;
    }



    // using dfs algo
    bool dfscheck(int node,int parent,vector<int> adj[],int v[]){
      v[node]=1;
      for(auto it:adj[node]){
          if(!v[it]){
              if(dfscheck(it,node,adj,v)) return true;
          }
          else if(it!=parent){
              return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int v[V]={0};
        for(int i=0;i<V;i++){
            if(!v[i]){
                if(dfscheck(i,-1,adj,v)) return true;
            }
        }
        return false;
    }