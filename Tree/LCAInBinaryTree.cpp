/*
    Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find 
    the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are 
    present in the tree or none of them are present.

    LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

    Examples:
    Input: root = [1,2,3,4,5,6,7], n1 = 5 , n2 = 6

    Output: 1
    Explanation: LCA of 5 and 6 is 1.
*/

// Optimal Recursive DFS
class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        if(root==NULL) return NULL;
        if(root->data==n1 || root->data==n2) return root;
        
        Node* left = lca(root->left,n1,n2);
        Node* right = lca(root->right,n1,n2);
        if(left && right) return root;
        return left?left:right;
    }
};

// Path Comparison Approach
class Solution {
  public:

    void solve(Node* root,vector<Node*>&v1,vector<Node*>&v2,vector<Node*>a,int n1,int n2){
        if(root==NULL) return;
        a.push_back(root);
        
        if(n1==root->data) v1=a;
        if(n2==root->data) v2=a;
        
        solve(root->left,v1,v2,a,n1,n2);
        solve(root->right,v1,v2,a,n1,n2);
    }
    Node* lca(Node* root, int n1, int n2) {
        vector<Node*>v1,v2,a;
        solve(root,v1,v2,a,n1,n2);
        
        if(v1.size()==0 && v2.size()==0) return NULL;
        int n = min(v1.size(),v2.size());
        for(int i=0;i<n;i++){
            if(v1[i]->data!=v2[i]->data){
                return i>0 ? v1[i-1] : NULL;
            }
        }
        return v1[n-1];
    }
};