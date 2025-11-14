/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        if(r1==nullptr && r2==nullptr){
            return true;
        }
        if(r1 && r2 && r1->data==r2->data){
            return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
        }
        return false;
    }
};