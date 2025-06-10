/*
    Given a binary tree and a target node, determine the minimum time required to burn the entire 
    tree if the target node is set on fire. In one second, the fire spreads from a node to its 
    left child, right child, and parent.
    Note: The tree contains unique values.

    Examples : 
    Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
    
    Output: 3
    Explanation: Initially 2 is set to fire at 0 sec 
    At 1 sec: Nodes 4, 5, 1 catches fire.
    At 2 sec: Node 3 catches fire.
    At 3 sec: Nodes 6, 7 catches fire.
    It takes 3s to burn the complete tree.
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        queue<Node*>q;
        unordered_map<Node*,Node*>mapping;
        q.push(root);
        Node* targetNode;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp->data==target) targetNode=temp;
            if(temp->left){
                q.push(temp->left);
                mapping[temp->left] = temp;
            }
            if(temp->right){
                q.push(temp->right);
                mapping[temp->right] = temp;
            }
        }

        unordered_map<Node*,bool>visited;
        int time=0;
        q.push(targetNode);
        visited[targetNode]=true;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && visited.find(temp->left)==visited.end()){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && visited.find(temp->right)==visited.end()){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(mapping[temp] && visited.find(mapping[temp])==visited.end()){
                    q.push(mapping[temp]);
                    visited[mapping[temp]]=true;
                }
            }
            time++;
        }
        return time-1;
    }
};