class Solution {
  public:
    
    void toposort(int node,int v[],vector<pair<int,int>>adj[],stack<int>&st){
        v[node]=1;
        for(auto it:adj[node]){
            int n=it.first;
            if(!v[n]){
                toposort(n,v,adj,st);
            }
        }
        st.push(node);
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>dis(N);
        int v[N]={0};
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!v[i]){
                toposort(i,v,adj,st);
            }
        }
        for(int i=0;i<N;i++){
            dis[i]=1e9;
        }
        dis[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dis[node]+wt<dis[v]){
                    dis[v]=dis[node]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
    }
};