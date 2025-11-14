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
    int res=0;
  public:
    int dfs(Node *root){
        if(!root){
            return 0;
        }
        int l=dfs(root->left);
        int r=dfs(root->right);
        res=max(res,l+r);
        return 1+max(l,r);
    }
    int diameter(Node* root) {
        // code here
        dfs(root);
        return res;
    }
};