/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int getSize(Node* root) {
        // code here
           if(root == nullptr){
            return 0;
        }
        int leftSubTreeHeight = getSize(root->left);
        int rightSubTreeHeight = getSize(root->right);
        
        return 1 + leftSubTreeHeight + rightSubTreeHeight;
    }
};