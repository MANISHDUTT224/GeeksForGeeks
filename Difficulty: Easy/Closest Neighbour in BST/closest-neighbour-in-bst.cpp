/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
void preorder(Node *curr,int k,int &ans){
    if(!curr){
        return;
    }
    if(curr->data<=k && curr->data>ans){
        ans=curr->data;
    }
    if(curr->data>k){
        preorder(curr->left,k,ans);
    }
    else{
        preorder(curr->right,k,ans);
    }
}
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans=-1;
        preorder(root,k,ans);
        return ans;
        
    }
};