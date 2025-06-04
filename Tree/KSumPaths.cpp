/*
    Given a binary tree and an integer k, determine the number of downward-only paths where the sum 
    of the node values in the path equals k. A path can start and end at any node within the tree 
    but must always move downward (from parent to child).

    Examples:
    Input: k = 7, root = [8,4,5,3,2,N,2,3,-2,N,1]

    Output: 3
*/

class Solution {
  public:
    void solve(Node* root,int k,vector<int>&path,int& cnt){
        if(root==NULL) return;
        path.push_back(root->data);
        
        solve(root->left,k,path,cnt);
        solve(root->right,k,path,cnt);
        
        int n=path.size(),sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=path[i];
            if(sum==k) cnt++;
        }
        path.pop_back();
    }
    int sumK(Node *root, int k) {
        vector<int>path;
        int cnt=0;
        solve(root,k,path,cnt);
        return cnt;
    }
};