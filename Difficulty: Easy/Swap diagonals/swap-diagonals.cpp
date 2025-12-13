class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
         int n = mat.size();
        int i=0;
        while(i<n){
            swap(mat[i][i] ,mat[i][n-1-i]);
            i++;
        }
    }
};
