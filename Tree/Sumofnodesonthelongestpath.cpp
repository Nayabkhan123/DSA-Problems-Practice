/*
    Given a binary tree root[], you need to find the sum of the nodes on the longest path from the 
    root to any leaf node. If two or more paths have the same length, the path with the maximum sum 
    of node values should be considered.

    Examples:
    Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
    
    Output: 13
    Explanation:
    The nodes (4, 2, 1, 6) above are part of the longest root to leaf path having 
    sum = (4 + 2 + 1 + 6) = 13
*/

class Solution {
  public:
    
    void solve(Node* root,int len,int sum,pair<int,int>& result){
        if(root==NULL){
            if(len>result.first){
                result.second = sum;
                result.first=len;
            }
            else if(len==result.first){
                result.second = max(sum,result.second);
            }
            return;
        }

        solve(root->left,len+1,sum+root->data,result);
        solve(root->right,len+1,sum+root->data,result);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        pair<int,int> result = {0,0};
        solve(root,0,0,result);
        return result.second;
    }
};


class Solution {
  public:
    
    void solve(Node* root,int len,int sum,pair<int,int>& result){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(len>result.first){
                result.second = sum+root->data;
                result.first=len;
            }
            else if(len==result.first){
                result.second = max(sum+root->data,result.second);
            }
            return;
        }
        solve(root->left,len+1,sum+root->data,result);
        solve(root->right,len+1,sum+root->data,result);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        pair<int,int> result = {0,0};
        solve(root,0,0,result);
        return result.second;
    }
};