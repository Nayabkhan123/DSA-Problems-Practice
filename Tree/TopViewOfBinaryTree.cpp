/*
    You are given a binary tree, and your task is to return its top view. The top view of a binary 
    tree is the set of nodes visible when the tree is viewed from the top.

    Note: 
    * Return the nodes from the leftmost node to the rightmost node.
    * If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, 
      consider the leftmost node only. 
    
    Examples:
    Input: root[] = [10, 20, 30, 40, 60, 90, 100]
    
    Output: [40, 20, 10, 30, 100]
    Explanation: The root 10 is visible.
    On the left, 40 is the leftmost node and visible, followed by 20.
    On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        vector<int>ans;
        q.push({root,0});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            Node* node = temp.first;
            int hd = temp.second;
            if(mp.find(hd)==mp.end()) mp[hd] = node->data;
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