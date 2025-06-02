class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
     int n=grid.size(),m=grid[0].size();
     vector<vector<int>>dist(n+1,vector<int>(m+1,0));
     if(grid[0][0]==0){
         dist[1][1]=1;
     }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(i+j==2){
                 continue;
             }
             if(grid[i-1][j-1]){
                 dist[i][j]=0;
             }
             else{
                 dist[i][j]=dist[i-1][j]+dist[i][j-1];
             }
         }
     }
     return dist[n][m];
    }
};