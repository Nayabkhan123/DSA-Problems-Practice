/*
    Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is 
    a Sum Tree otherwise, return false.

    A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its 
    left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be 
    considered to be 0. A leaf node is also considered a Sum Tree.

    Examples:

    Input: 3 1 2
    Output: true
    Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root 
    node. Therefore,the given binary tree is a sum tree.
*/

class Solution {
  public:
    pair<bool,int> sumTree(Node* root){
        if(root==NULL) return {true,0};
        if(root->left==NULL&&root->right==NULL) 
            return {true,root->data};
        
        pair<bool,int> left= sumTree(root->left);
        pair<bool,int> right = sumTree(root->right);
        
        int sum = left.second+right.second;
        bool check = left.first&&right.first&&root->data == sum;
        return {check,root->data+sum};
    }
    bool isSumTree(Node* root) {
        pair<bool,int> ans = sumTree(root);
        return ans.first;
    }
};