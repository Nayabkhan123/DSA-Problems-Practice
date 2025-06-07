/*
    Given a binary tree with a value associated with each node. Your task is to select a subset 
    of nodes such that the sum of their values is maximized, with the condition that no two 
    selected nodes are directly connected that is, if a node is included in the subset, neither 
    its parent nor its children can be included.

    Examples:
    Input: root[] = [11, 1, 2]

    Output: 11
    Explanation: The maximum sum is obtained by selecting the node 11.
*/


class Solution {
  public:
    pair<int,int> solve(Node* root){
        if(root==NULL) return {0,0};
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        int take = root->data + left.second + right.second;
        int notTake = max(left.first,left.second) + max(right.first,right.second);
        return {take,notTake};
    }
    int getMaxSum(Node *root) {
        pair<int,int>ans;
        ans = solve(root);
        return max(ans.first,ans.second);
        
    }
};