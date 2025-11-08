class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
         int n = mat.size(), m = mat[0].size();
        vector<vector<int>> curr(m, vector<int> (k+1, 0));
        vector<vector<int>> prev(m, vector<int> (k+1, 0));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int sum = 0;sum<=k;sum++){
                    // Resetting(Takes place after curr is stored in prev in previous run 
                    curr[j][sum] = 0;
                    
                    // Base case
                    if(i == 0 and j == 0){
                        curr[j][mat[0][0]] = 1;
                    }
                    
                    
                    if(sum-mat[i][j]>=0){
                        if(i>0)curr[j][sum] += prev[j][sum-mat[i][j]];
                        if(j>0)curr[j][sum] += curr[j-1][sum-mat[i][j]];
                    }
                }
                prev = curr;
            }
        }
        
        return curr[m-1][k];
    }
};