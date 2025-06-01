/*
    You are given the root of a binary tree. Your task is to return the left view of the binary tree. 
    The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

    If the tree is empty, return an empty list.

    Examples :
    Input: root[] = [1, 2, 3, 4, 5, N, N]

    Output: [1, 2, 4]
    Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.
*/

// using recursion
class Solution {
  public:
    void leftViewStore(Node* root,vector<int>& ans,int lvl){
        if(root==NULL) return ;
        if(lvl==ans.size()) ans.push_back(root->data);
        leftViewStore(root->left,ans,lvl+1);
        leftViewStore(root->right,ans,lvl+1);
    }
    vector<int> leftView(Node *root) {
        vector<int>ans;
        leftViewStore(root,ans,0);
        return ans;
    }
};

// using level order traversal
class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                if (i == 0) ans.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};