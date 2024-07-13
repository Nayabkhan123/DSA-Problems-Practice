//using bfs algo
//gfg
bool check(int start,int color[],vector<int>adj[]){
        color[start]=0;
	    queue<int>q;
	    q.push(start);
        while(!q.empty()){
	        int node = q.front();
	        
	        q.pop();
	        for(auto it:adj[node]){
	            if(color[it]==-1){
	               color[it]= !color[node];
	               q.push(it);
	                
	            }
	            else if(color[it]==color[node]){
	                return false;
	            }
	        }
	    }
	    return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++){
	        color[i]=-1;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!check(i,color,adj))
	            return false;
	        }
	    }
	    return true; 
	}


// using dfs algo
//leetcode

class Solution {
public:

    bool dfs(int start,int col,int color[],vector<vector<int>>&graph){
        color[start]=col;
        for(auto it:graph[start]){
            if(color[it]==-1){
                // color[it]=!color[start];
                if(dfs(it,!col,color,graph)==false) return false;
            }
            else if(color[it]==color[start]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        int color[V];
        for(int i=0;i<V;i++){
            color[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};