class Solution {
  public:
  
    bool dfscheck(int &node,int vis[],int pathvis[],vector<int>adj[],int check[]){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfscheck(it,vis,pathvis,adj,check)==true){
                
                return true;
                }
            }
            else if(pathvis[it]){
                
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathvis[V]={0};
        int check[V]={0};
        vector<int>v;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfscheck(i,vis,pathvis,adj,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) v.push_back(i);
        }
        return v;
    }
};

// using topological sort algo
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>revadj[V];
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                revadj[it].push_back(i);
                indegree[i]++;
            }
        }
    
       queue<int>q;
       for(int i=0;i<V;i++){
           if(indegree[i]==0){
               q.push(i);
           }
       }
       vector<int>v;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           v.push_back(node);
           for(auto it:revadj[node]){
               indegree[it]--;
               if(indegree[it]==0){
                   q.push(it);
               }
           }
       }
       sort(v.begin(),v.end());
       return v;
    }