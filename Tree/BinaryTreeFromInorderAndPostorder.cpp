/*
    Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays inorder[] 
    and postorder[] respectively. The task is to construct a unique binary tree from these traversals 
    and return its root.
    Driver code will print the preorder traversal of the constructed tree.

    Note: The inorder and postorder traversals contain unique values, and every value present in the 
    postorder traversal is also found in the inorder traversal.

    Examples:

    Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
    Output: [1, 2, 4, 8, 5, 3, 6, 7]
*/
// Time & Space Complexity -> O(n)
class Solution {
  public:
    Node* solve(vector<int>& postorder,int& index,int startIdx,int endIdx,
                unordered_map<int,int>&mapping){

        if(startIdx>endIdx || index<0){
            return NULL;
        }
        int element = postorder[index--];
        Node* root = new Node(element);
        int pos = mapping[element];
        root->right = solve(postorder,index,pos+1,endIdx,mapping);
        root->left = solve(postorder,index,startIdx,pos-1,mapping);
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        unordered_map<int,int>mapping;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mapping[inorder[i]]=i;
        }
        int index=n-1;
        return solve(postorder,index,0,n-1,mapping);
        
    }
};

// Time (worst case) -> O(n²), Space (worst case) -> O(n) (due to recursion stack)
class Solution {
  public:
    int findIdx(vector<int>& inorder,int n,int element){
        for(int i=0;i<n;i++){
            if(element == inorder[i]){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int>& inorder, vector<int>& postorder,int& index,int& n,int startIdx,int endIdx){
        if(startIdx>endIdx || index<0){
            return NULL;
        }
        int element = postorder[index--];
        Node* root = new Node(element);
        int pos = findIdx(inorder,n,element);
        root->right = solve(inorder,postorder,index,n,pos+1,endIdx);
        root->left = solve(inorder,postorder,index,n,startIdx,pos-1);
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int index=inorder.size()-1;
        int n=inorder.size();
        return solve(inorder,postorder,index,n,0,n-1);
        
    }
};