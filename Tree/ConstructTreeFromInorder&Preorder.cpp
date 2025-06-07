/*
    Given two arrays representing the inorder and preorder traversals of a binary tree, construct 
    the tree and return the root node of the constructed tree.

    Note: The output is written in postorder traversal.

    Examples:
    Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
    Output: [8, 7, 6, 1]
*/

class Solution {
  public:
    Node* solve(vector<int>&preorder,int& index,
                int startIdx,int endIdx,unordered_map<int,int>&mapping){
        if(startIdx > endIdx || index>=preorder.size()) return NULL;
        
        int element = preorder[index++];
        int position = mapping[element];
        Node* root = new Node(element);
        
        root->left = solve(preorder,index,startIdx,position-1,mapping);
        root->right = solve(preorder,index,position+1,endIdx,mapping);
        
        return root;
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int>mapping;
        for(int i=0;i<preorder.size();i++){
            mapping[inorder[i]] = i;
        }
        int preorderindex = 0;
        Node* ans = solve(preorder,preorderindex,0,preorder.size()-1,mapping);
        return ans;
    }
};

class Solution {
  public:
    Node* solve(vector<int>&inorder,vector<int>&preorder,int& n,int& index,
                int startIdx,int endIdx,unordered_map<int,int>&mapping){
        if(startIdx > endIdx || index>=n) return NULL;
        
        int element = preorder[index++];
        int position = mapping[element];
        Node* root = new Node(element);
        
        root->left = solve(inorder,preorder,n,index,startIdx,position-1,mapping);
        root->right = solve(inorder,preorder,n,index,position+1,endIdx,mapping);
        
        return root;
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int>mapping;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mapping[inorder[i]] = i;
        }
        int preorderindex = 0;
        Node* ans = solve(inorder,preorder,n,preorderindex,0,n-1,mapping);
        return ans;
    }
};

class Solution {
  public:
    int getIndexInInorder(vector<int>&inorder, int n, int element){
        for(int i=0;i<n;i++){
            if(inorder[i]==element) return i;
        }
        return -1;
    }
    Node* solve(vector<int>&inorder,vector<int>&preorder,int& n,int& index,int startIdx,int endIdx){
        if(startIdx > endIdx || index>=n) return NULL;
        
        int element = preorder[index++];
        int position = getIndexInInorder(inorder,n,element);
        Node* root = new Node(element);
        
        root->left = solve(inorder,preorder,n,index,startIdx,position-1);
        root->right = solve(inorder,preorder,n,index,position+1,endIdx);
        
        return root;
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preorderindex = 0;
        int n = inorder.size();
        Node* ans = solve(inorder,preorder,n,preorderindex,0,n-1);
        return ans;
    }
};
