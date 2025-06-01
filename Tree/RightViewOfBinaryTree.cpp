/*
    Given a Binary Tree, Your task is to return the values visible from Right view of it.

    Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

    Examples :
    Input: root = [1, 2, 3, 4, 5]

    Output: [1, 3, 5]
*/

// using recursion
class Solution {
  public:
    void rightViewStore(Node* root,vector<int>&ans,int lvl){
        if(root==NULL) return ;
        if(lvl == ans.size()) ans.push_back(root->data);
        rightViewStore(root->right,ans,lvl+1);
        rightViewStore(root->left,ans,lvl+1);
    }
    vector<int> rightView(Node *root) {
        vector<int>ans;
        rightViewStore(root,ans,0);
        return ans;
    }
};

// using level order traversal
class Solution {
  public:
    vector<int> rightView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                if(i==0) ans.push_back(temp->data);
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return ans;
    }
};