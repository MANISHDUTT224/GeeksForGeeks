/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  
    int solve(Node *root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int sum = root->data+left+right;
        root->data = (left+right);
        return sum;
    }
  public:
    void toSumTree(Node *root) {
        // code here
        solve(root);
    }
};