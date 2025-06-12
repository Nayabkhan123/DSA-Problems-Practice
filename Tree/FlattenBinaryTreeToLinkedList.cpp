/*
    Given the root of a binary tree, flatten the tree into a "Linked list":

    The "linked list" should use the same Node class where the right child pointer points to the next 
    node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
    Examples:

    Input: 1 2 5 3 4 N 6
    Output : 1 2 3 4 5 6 
*/

class Solution {
  public:
    void flatten(Node *root) {
        while(root){
            if(root->left){
                Node* pred = root->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right = root->right;
                root->right=root->left;
            }
            root=root->right;
        }
    }
};