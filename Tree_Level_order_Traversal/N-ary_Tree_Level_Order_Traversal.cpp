/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> sol;
        if(root==NULL)return sol;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                for(auto it: curr->children)
                {
                    q.push(it);
                }
                
            }
            sol.push_back(temp);
        }
        return sol;
    }
};