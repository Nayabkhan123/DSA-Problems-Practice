class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int node=it.second;
            pq.pop();
            for(auto it : adj[node]){
                int adjnode=it.first;
                int edwt=it.second;
                if(dis+edwt<dist[adjnode]){
                    dist[adjnode]=dis+edwt;
                    pq.push({dis+edwt,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dis+edwt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};