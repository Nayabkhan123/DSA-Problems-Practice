/*
    Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
    In zig zag traversal starting from the first level go from left to right for odd-numbered levels 
    and right to left for even-numbered levels.

    Examples:
    Input: [1,2,3,4,5,6,7]

    Output: [1, 3, 2, 4, 5, 6, 7]
    Explanation:
    For level 1 going left to right, we get traversal as {1}.
    For level 2 going right to left, we get traversal as {3,2}.
    For level 3 going left to right, we get traversal as {4,5,6,7}.
    Merging all this traversals in single array we get {1,3,2,4,5,6,7}.

*/

//one more approch (LEETCODE)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        deque<TreeNode*>dq;
        dq.push_back(root);
        bool leftToRight = true;
        vector<vector<int>>ans;
        while(!dq.empty()){
            int n=dq.size();
            vector<int>currLevel;
            for(int i=0;i<n;i++){
                if(leftToRight){
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    currLevel.push_back(node->val);
                    if(node->left){
                        dq.push_back(node->left);
                    }
                    if(node->right){
                        dq.push_back(node->right);
                    }
                }
                else{
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    currLevel.push_back(node->val);
                    if(node->right){
                        dq.push_front(node->right);
                    }
                    if(node->left){
                        dq.push_front(node->left);
                    }
                }
            }
            ans.push_back(currLevel);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};

// without reverse() or deque
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        bool flag = false;
        
        while(!q.empty()){
            int n=q.size();
            vector<int>curr(n);
            
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                int index = flag ? n-i-1 : i;
                curr[index]=temp->data;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.insert(ans.end(),curr.begin(),curr.end());
            flag=!flag;
        }
        return ans;
        
    }
};

// with deque
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        bool flag = false;
        
        while(!q.empty()){
            int n=q.size();
            deque<int>dq;
            
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                flag ? dq.push_front(temp->data) : dq.push_back(temp->data); 
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.insert(ans.end(),dq.begin(),dq.end());
            flag=!flag;
        }
        return ans;
        
    }
};

// with reverse()
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        bool flag = false;
        
        while(!q.empty()){
            vector<int>curr;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                curr.push_back(temp->data);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(flag) reverse(curr.begin(),curr.end());
            ans.insert(ans.end(),curr.begin(),curr.end());
            flag=!flag;
        }
        return ans;
        
    }
};