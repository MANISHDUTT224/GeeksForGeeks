/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node * pred(Node* nd , int key){
        if(nd == NULL)return NULL;
        if(nd->data > key) return pred(nd->left , key);
        else {
            Node * tp = pred(nd->right , key);
            if(tp!=NULL){
                if(tp->data > nd->data)return tp;
            }
            return nd;
        }
    }
    Node * suc(Node * nd , int key){
        if(nd == NULL)return NULL;
        if(nd->data <key)return suc(nd->right , key);
        else{
            Node* tp = suc(nd->left , key);
            if(tp!=NULL){
                if(tp->data < nd->data)return tp;
            }
            return nd;
        }
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL ,*succ = NULL;
        // traverse(root , key , pre , succ);
        pre = pred(root , key-1);
        succ = suc(root , key+1);
        return {pre , succ};
    }
};