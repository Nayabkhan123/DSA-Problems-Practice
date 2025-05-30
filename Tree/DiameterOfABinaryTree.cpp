/*
    Given a binary tree, the diameter (also known as the width) is defined as the number of edges 
    on the longest path between two leaf nodes in the tree. This path may or may not pass through 
    the root. Your task is to find the diameter of the tree.

    Examples:

    Input: root[] = [1, 2, 3]

    Output: 2
    Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).
*/
// O(N)
class Solution {
    pair<int,int> fastdiameter(Node* root){
        if(root==NULL) return {0,0};
        pair<int,int> left = fastdiameter(root->left);
        pair<int,int> right = fastdiameter(root->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
        int d = max(op1,max(op2,op3));
        int h = max(left.second,right.second) + 1;
        return {d,h};
    }
  public:
    int diameter(Node* root) {
        pair<int,int> ans = fastdiameter(root);
        return ans.first;
    }
};

// O(N*N)
class Solution {
  public:
    int height(Node* root){
        if(root==NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right) + 1;
    }
    int diameter(Node* root) {
        if(root==NULL) return 0;
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right);
        
        return max(op1,max(op2,op3));
    }
};