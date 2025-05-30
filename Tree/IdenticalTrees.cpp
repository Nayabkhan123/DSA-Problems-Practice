/*
    Given two binary trees with their root nodes r1 and r2, return true if both of them are identical, 
    otherwise, false.

    Examples:
    Input:
        1           1
      /   \       /   \
     2     3     2     3
    Output: true
    Explanation: 
    There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, 
    left child of 1 is 2 and right child of 1 is 3.
*/

// Time Complexity: O(n) , Space Complexity: O(h)
class Solution {
  public:
    bool isIdentical(Node *r1, Node *r2) {
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1==NULL || r2==NULL){
            return false;
        }        
        if(r1->data == r2->data){
            bool left = isIdentical(r1->left,r2->left);
            bool right = isIdentical(r1->right,r2->right);
            return left&&right;
        }
        else{
            return false;
        }
    }
};