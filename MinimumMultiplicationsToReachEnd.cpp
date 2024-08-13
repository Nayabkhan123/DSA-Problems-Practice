class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        queue<pair<int,int>>q;
        vector<int>dist(100000,1e9);
        q.push({start,0});
        dist[start]=0;
        int mod=100000;
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            for(auto it:arr){
                int num=(node*it)%mod;
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    if(end==num) return steps+1;
                    q.push({num,steps+1});
                }
                
                
            }
        }
        return -1;
    }
};