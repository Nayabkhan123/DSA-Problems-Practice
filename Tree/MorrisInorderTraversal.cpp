/*
    Given a Binary Tree, your task is to return its In-Order Traversal using Morris Traversal.

    An inorder traversal first visits the left child (including its entire subtree), then visits the node, 
    and finally visits the right child (including its entire subtree).

    Follow Up: Try solving this with O(1) auxiliary space.

    Examples:
    Input: root[] = [1, 2, 3, 4, 5] 
        
    Output: [4, 2, 5, 1, 3]
    Explanation: The in-order traversal of the given binary tree is [4, 2, 5, 1, 3].
*/

class Solution {
  public:
    Node* find(Node* root){
        Node* temp = root->left;
        while(temp->right && temp->right != root){
            temp=temp->right;
        }
        return temp;
    }
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        while(root!=NULL){
            if(root->left==NULL){
                ans.push_back(root->data);
                root=root->right;
            }
            else{
                Node* pred = find(root);
                if(pred->right==NULL){
                    pred->right = root;
                    root=root->left;
                    
                }
                else{
                    pred->right = NULL;
                    ans.push_back(root->data);
                    root=root->right;
                }
            }
        }
        return ans;
    }
};