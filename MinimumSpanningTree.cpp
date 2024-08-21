class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            int wt=it.first;
            int node=it.second;
            pq.pop();
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjnode=it[0];
                int edwt=it[1];
                if(!vis[adjnode]){
                    pq.push({edwt,adjnode});
                }
            }
        }
        return sum;
    }
};