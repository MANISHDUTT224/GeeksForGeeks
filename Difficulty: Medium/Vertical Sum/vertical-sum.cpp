/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
     void recursive_count_lines(Node*p,int cur,int*left,int*rite) {
        if (p->left) {
            if (*left>cur-1) *left=cur-1;
            recursive_count_lines(p->left,cur-1,left,rite);
        }
        if (p->right) {
            if (*rite<cur+1) *rite=cur+1;
            recursive_count_lines(p->right,cur+1,left,rite);
        }
    }
    void recursive_get_sums(Node*p,int line,vector<int>&v) {
        v[line]+=p->data;
        if (p->left ) recursive_get_sums(p->left,line-1,v);
        if (p->right) recursive_get_sums(p->right,line+1,v);
        
    }

    vector<int> verticalSum(Node* root) {
        vector<int>v;
        if (!root) return v;
        
        //get left-most and right-most line numbers, with root at line 0
        int left=0,rite=0; //left will be <=0, and rite will be >=0
        recursive_count_lines(root,0,&left,&rite);

        for (int i=left;i<=rite;i++) v.push_back(0);
        recursive_get_sums(root,-left,v);

        return v;
    }
};