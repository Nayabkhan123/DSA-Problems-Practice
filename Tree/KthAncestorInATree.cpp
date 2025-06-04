/*
    Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete 
    the function kthAncestor(), the function should return the kth ancestor of the given node in 
    the binary tree. If there does not exist any such ancestor then return -1.
    Note:
    1. It is guaranteed that the node exists in the tree.
    2. All the nodes of the tree have distinct values.

    Examples :
    Input: k = 2, node = 4, [1,2,3,4,5]

    Output: 1
    Explanation:
    Since, k is 2 and node is 4, so we first need to locate the node and look k times its ancestors. 
    Here in this Case node 4 has 1 as his 2nd Ancestor aka the root of the tree.
*/

class Solution {
  public:
    int solve(Node* root,int& k,int node){
        if(root==NULL) return -1;
        if(node==root->data){
            return root->data;
        }
        int leftCall = solve(root->left,k,node);
        int rightCall = solve(root->right,k,node);
        if((leftCall != -1 || rightCall != -1) && k>0){
            k--;
            if(k==0) return root->data;
        }
        return leftCall == -1 ? rightCall : leftCall;
    }
    int kthAncestor(Node *root, int k, int node) {
        if(k==0) return -1;
        int ans = solve(root,k,node);
        return k==0 ? ans : -1;
    }
};

class Solution {
  public:
    Node* solve(Node* root,int node,vector<int>&path){
        if(root==NULL) return NULL;
        path.push_back(root->data);
        if(root->data == node){
            return root;
        }
        Node* left = solve(root->left,node,path);
        Node* right = solve(root->right,node,path);
        if(left != NULL || right != NULL) return left == NULL ? right : left;
        path.pop_back();
        return NULL;
    }
    int kthAncestor(Node *root, int k, int node) {
        vector<int>path;
        solve(root,node,path);
        int n = path.size();
        return n-1-k >=0 ? path[n-1-k] : -1;
    }
};


class Solution {
  public:
    void solve(Node* root,int k,int node,vector<int>way,vector<int>&path){
        if(root==NULL) return;
        way.push_back(root->data);
        if(root->data == node){
            path=way;
            return;
        }
        solve(root->left,k,node,way,path);
        solve(root->right,k,node,way,path);
    }
    int kthAncestor(Node *root, int k, int node) {
        vector<int>path;
        solve(root,k,node,{},path);
        int n = path.size();
        return n-1-k >=0 ? path[n-1-k] : -1;
    }
};