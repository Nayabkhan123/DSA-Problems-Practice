class Solution{
    public:
    
    vector<int> topo(vector<int>adj[],int V){
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        vector<int>v;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            v.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return v;
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string str1=dict[i];
            string str2=dict[i+1];
            int len=min(str1.size(),str2.size());
            for(int j=0;j<len;j++){
                if(str1[j]!=str2[j]){
                    adj[str1[j] - 'a'].push_back(str2[j] -'a');
                    break;
                }
            }
        }
        vector<int>ans=topo(adj,K);
        string s="";
        for(auto it:ans){
            s=s+char(it + 'a');
        }
        return s;
    }
};