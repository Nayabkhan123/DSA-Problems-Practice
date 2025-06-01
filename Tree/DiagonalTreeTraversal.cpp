/*
    Given a Binary Tree, return the diagonal traversal of the binary tree.

    Consider lines of slope -1 passing between nodes. Given a Binary Tree, return a single list 
    containing all diagonal elements in a binary tree belonging to same line.
    If the diagonal element are present in two different subtrees then left subtree diagonal element 
    should be taken first and then right subtree. 

    Examples :

    Input : root = [8, 3, 10, 1, 6, N, 14, N, N, 4, 7, 13]

    Output : [8, 10, 14, 3, 6, 7, 13, 1, 4]
    Explanation:
    Diagonal Traversal of binary tree : 8 10 14 3 6 7 13 1 4
*/

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            while(node){
                ans.push_back(node->data);
                if(node->left) q.push(node->left);
                node=node->right;
            }
        }
        return ans;
    }
};