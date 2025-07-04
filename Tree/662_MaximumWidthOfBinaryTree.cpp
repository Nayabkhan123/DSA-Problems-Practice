/*
    Given the root of a binary tree, return the maximum width of the given tree.

    The maximum width of a tree is the maximum width among all levels.

    The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

    It is guaranteed that the answer will in the range of a 32-bit signed integer.

    

    Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: 4
    Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int maxWidth = 0,first,last;
        while(!q.empty()){
            int n=q.size();
            first = q.front().second;
            last = q.back().second;
            maxWidth = max(maxWidth,last-first+1);
            for(int i=0;i<n;i++){
                auto temp = q.front();
                q.pop();
                TreeNode* node = temp.first;
                unsigned long long idx = temp.second - first;
                if(node->left){
                    q.push({node->left,2*idx+1});
                }
                if(node->right){
                    q.push({node->right,2*idx+2});
                }
            }
        }
        return maxWidth;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,0});
        unsigned long long maxWidth = 0,first,last;
        while(!q.empty()){
            int n=q.size();
            first = q.front().second;
            last = q.back().second;
            maxWidth = max(maxWidth,last-first+1);
            for(int i=0;i<n;i++){
                auto temp = q.front();
                q.pop();
                TreeNode* node = temp.first;
                unsigned long long idx = temp.second;
                if(node->left){
                    q.push({node->left,2*idx+1});
                }
                if(node->right){
                    q.push({node->right,2*idx+2});
                }
            }
        }
        return maxWidth;
    }
};