class Solution {
  public:
    void rec(vector<int>&preorder,int s,int e,vector<int>&ans){
        if(s>e){
            return;
        }
        if(s==e){
            ans.push_back(preorder[s]);
        }
        int i=0;
        for(i=s+1;i<=e;i++){
            if(preorder[s]<preorder[i]){
                break;
            }
        }
        rec(preorder,s+1,i-1,ans);
        rec(preorder,i,e,ans);
    }
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        vector<int>ans;
        rec(preorder,0,preorder.size()-1,ans);
        return ans;
    }
};