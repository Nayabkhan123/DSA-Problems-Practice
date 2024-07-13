	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N];
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    int indegree[N]={0};
	    for(int i = 0;i<N;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    int cnt=0;
	    queue<int>q;
	    for(int i = 0;i<N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    if(cnt==N){
	        return true;
	    }
	    return false;
	    
	}