/*
    Given the root of a binary tree, flatten the tree into a "Linked list":

    The "linked list" should use the same Node class where the right child pointer points to the next 
    node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
    Examples:

    Input: 1 2 5 3 4 N 6
    Output : 1 2 3 4 5 6 
*/

// using stack 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()) curr->right = st.top();
            curr->left = NULL;
        }
    }
};

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
                root->left = NULL;
            }
            root=root->right;
        }
    }
};

// using reverse post-order traversal
class Solution {
  public:
    Node* prev = nullptr;

    void helper(Node* node) {
        if (!node) return;

        helper(node->right);
        helper(node->left);

        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
    void flatten(Node *root) {
        helper(root);
    }
};