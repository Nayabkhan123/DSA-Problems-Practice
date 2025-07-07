/*
    Given a binary tree, determine if it is height-balanced. A binary tree is considered 
    height-balanced if the absolute difference in heights of the left and right subtrees 
    is at most 1 for every node in the tree.

    Examples:
    Input: root[] = [10, 20, 30, 40, 60]

    Output: true
    Explanation: The height difference between the left and right subtrees at all nodes is at most 1. 
    Hence, the tree is balanced.
*/
// timeComplexity -> O(N)
class Solution {
public:
    int check(TreeNode* root){
        if(root==NULL) return 0;
        int left = check(root->left);
        if(left == -1) return -1;
        int right = check(root->right);
        if(right == -1) return -1;
        if(abs(left-right) > 1) return -1;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1 ;
    }
};

// timeComplexity -> O(N)
class Solution {
  public:
    pair<bool,int> balanced(Node* root){
        if(root == NULL) return {true,0};
        pair<bool,int> left = balanced(root->left);
        pair<bool,int> right = balanced(root->right);
        int diff = abs(left.second - right.second) <= 1;
        return {left.first && right.first && diff , max(left.second,right.second) + 1};
    }
    bool isBalanced(Node* root) {
        pair<bool,int> ans = balanced(root);
        return ans.first;
    }
};

// timeComplexity -> O(N^2)
class Solution {
  public:
    int height(Node* root){
        if(root==NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right) + 1;
    }
    bool isBalanced(Node* root) {
        if(root==NULL) return true;
        bool left = isBalanced(root->left);
        if(abs(height(root->left) - height(root->right)) > 1) return false;
        bool right = isBalanced(root->right);
        return left && right ;
    }
};