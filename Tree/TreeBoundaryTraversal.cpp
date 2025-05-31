/*
    Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. 
    You must prefer the left child over the right child when traversing. Do not include leaf nodes 
    in this section.

    Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

    Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to 
    the root, traversed in reverse order. You must prefer the right child over the left child when 
    traversing. Do not include the root in this section if it was already included in the left boundary.

    Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left 
    or right boundary. 

    Examples:

    Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
    Output: [1, 2, 4, 8, 9, 6, 7, 3]
*/

class Solution {
  public:
    void left(Node* root, vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left) left(root->left,ans);
        else if(root->right) left(root->right,ans);
        
    }
    void leaf(Node* root,vector<int>& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) ans.push_back(root->data);
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    void right(Node* root, vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        if(root->right) right(root->right,ans);
        else if(root->left) right(root->left,ans);
        ans.push_back(root->data);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        ans.push_back(root->data);
        left(root->left,ans);
        leaf(root->left,ans);
        leaf(root->right,ans);
        right(root->right,ans);
        return ans;
    }
};