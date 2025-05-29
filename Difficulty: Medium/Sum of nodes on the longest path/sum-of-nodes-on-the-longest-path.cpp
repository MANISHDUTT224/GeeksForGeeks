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
    int maxlen=0,maxsm=0;
    void dfs(Node *node,int curlen,int cursum){
        if(!node){
            return;
        }
        curlen++;
        cursum+=node->data;
        if(!node->left && !node->right){
            if(curlen>maxlen){
                maxlen=curlen;
                maxsm=cursum;
            }
            else if(curlen==maxlen){
                maxsm=max(maxsm,cursum);
            }
        }
        dfs(node->left,curlen,cursum);
          dfs(node->right,curlen,cursum);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        maxlen=0;maxsm=0;
        dfs(root,0,0);
        return maxsm;
    }
};