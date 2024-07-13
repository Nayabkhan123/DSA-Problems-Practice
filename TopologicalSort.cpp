//basic institution 
void dfs(int node,int v[],vector<int>adj[],stack<int>&st){
	    v[node]=1;
	    for(auto it:adj[node]){
	        if(!v[it]){
	            dfs(it,v,adj,st);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int v[V]={0};
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!v[i]){
	          dfs(i,v,adj,st);  
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}


// kahn's algorithm

vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	   vector<int>topo;
	   while(!q.empty()){
	       int node=q.front();
	       topo.push_back(node);
	       q.pop();
	       
	       for(auto it:adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0) q.push(it);
	       }
	   }
	   return topo;
	}