/*
    Given a binary tree, return an array where elements represent the bottom view of the binary 
    tree from left to right.

    Note: If there are multiple bottom-most nodes for a horizontal distance from the root, 
    then the latter one in the level traversal is considered.

    Examples :
    Input: 10 20 30 40 60
    Output: 40 20 60 30
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto temp = q.front();
            Node* node = temp.first;
            q.pop();
            int hd = temp.second;
            mp[hd]=node->data;
            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};