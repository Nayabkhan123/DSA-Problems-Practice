/*
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:
    Input: root = [1,2,2,3,4,4,3]
    Output: true
*/

class Solution {
public:
    bool check(TreeNode* p,TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val!=q->val) return false;

        bool left = check(p->left,q->right);
        bool right = check(p->right,q->left);
        return left && right;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root,root);
    }
};