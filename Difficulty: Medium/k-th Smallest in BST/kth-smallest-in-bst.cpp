/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
     int kSmallest(Node* root, int& k){
        if(!root) return -1;
        int lft=kSmallest(root->left, k);
        if(lft!=-1) return lft;
        if(k==1) return root->data;
        k--;
        return kSmallest(root->right, k);
    }
    int kthSmallest(Node *root, int k) {
        return kSmallest(root, k);
    }
};