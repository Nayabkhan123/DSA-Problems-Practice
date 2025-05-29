/*
    Given a binary tree, find its reverse level order traversal. ie- the traversal must begin from the last level.

    Examples :

    Input: root = [10, 20, 30, 40, 60]
        10
        /  \
       20   30
       / \ 
      40  60
    Output: 40 60 20 30 10
    Explanation: Traversing level 2 : 40 60, Traversing level 1 : 20 30, Traversing level 0 : 10
*/

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        queue<Node*>q;
        q.push(root);
        vector<int>b;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            b.push_back(temp->data);
           
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
        reverse(b.begin(),b.end());
        return b;
    }
};

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>a;
        vector<int>b;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp==NULL){
                a.push_back(b);
                b={};
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                b.push_back(temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        vector<int>c;
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                c.push_back(a[i][j]);
            }
        }
        return c;
    }
};