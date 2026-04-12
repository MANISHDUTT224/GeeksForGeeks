class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
          map<int,int>mpp;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[i].size();j++){
                if(mpp.find(i-j)!=mpp.end() && mpp[i-j]!=mat[i][j])return false;
                mpp[i-j] = mat[i][j];
            }
        }
        return true;
    }
};