/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
     void inorder(Node *root,int target,int k,priority_queue<pair<int,int>> &pq)
   {
        if(root==NULL)
         return ;
         
         inorder(root->left,target,k,pq);
         int curr = root->data;
         pq.push({abs(curr - target),curr});
         if(pq.size()>k)
         pq.pop();
         inorder(root->right,target,k,pq);
   }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        priority_queue<pair<int,int>> pq;
        
        inorder(root,target,k,pq);
        
        vector<int> ans;
        while(!pq.empty())
        {
             ans.push_back(pq.top().second);
             pq.pop();
        }
        return ans;
    }
};