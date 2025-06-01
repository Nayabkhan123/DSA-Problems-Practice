/*
    Given a root of a Binary Tree, find the vertical traversal of it starting from the leftmost 
    level to the rightmost level.
    If there are multiple nodes passing through a vertical line, then they should be printed as 
    they appear in level order traversal of the tree.

    Examples:

    Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, N, N, N, 8, N, 9]      
    Output: [[4], [2], [1, 5, 6], [3, 8], [7], [9]]
    Explanation: The below image shows the horizontal distances used to print vertical traversal 
    starting from the leftmost level to the rightmost level.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp;
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();
            TreeNode* currNode = temp.first;
            int lvl = temp.second.first;
            int hd = temp.second.second;
            mp[hd][lvl].insert(currNode->val);
            if(currNode->left){
                q.push({currNode->left,{lvl+1,hd-1}});
            }
            if(currNode->right){
                q.push({currNode->right,{lvl+1,hd+1}});
            }
        }
        
        for(auto i : mp){
            vector<int>col;
            for(auto j:i.second){
                for(auto k:j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
    
};

// why not this ?
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            mp[temp.second].push_back(temp.first->data);
            if(temp.first->left){
                q.push({temp.first->left,temp.second-1});
            }
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
            }
        }
        vector<vector<int>>ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};