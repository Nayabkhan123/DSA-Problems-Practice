/*
    You are given the root of a binary search tree (BST) and an integer val.

    Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
    If such a node does not exist, return null.

    Example 1:
    Input: root = [4,2,7,1,3], val = 2
    Output: [2,1,3]
*/

// Iterative Approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val == val){
                return root;
            }
            else if(root->val < val){
                root=root->right;
            }
            else root = root->left;
        }
        return NULL;
    }
};

// Recursive Approach
class Solution {
public:
    TreeNode* solve(TreeNode* root, int val){
        if(root==NULL) return NULL;
        if(root->val == val) return root;
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        if(root->val>val) 
        left=solve(root->left,val);
        else 
        right = solve(root->right,val);
        return left ? left : right;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};
