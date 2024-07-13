class Solution {
  public:
    bool dfscheck(int start,int vis[],int pathvis[],vector<int>adj[]){
        vis[start]=1;
        pathvis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                if(dfscheck(it,vis,pathvis,adj)==true) return true;
            }
            else if(pathvis[it]==1){
                return true;
            }
        }
        pathvis[start]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfscheck(i,vis,pathvis,adj)==true) return true;
            }
        }
        return false;
    }
};

//kanh's algo
 bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(cnt==V){
            return false;
        }
        return true;
    }