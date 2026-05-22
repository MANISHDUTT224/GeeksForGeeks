class Solution {
  public:
     void dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             int n, int m) {
        
        vis[row][col] = 1;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               grid[nr][nc] == 1 &&
               !vis[nr][nc]) {
                
                dfs(nr, nc, grid, vis, n, m);
            }
        }
    }
    
    int cntOnes(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            
            if(grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, grid, vis, n, m);
            }
            
            if(grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1, grid, vis, n, m);
            }
        }
        
        for(int j = 0; j < m; j++) {
            
            if(grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, grid, vis, n, m);
            }
            
            if(grid[n - 1][j] == 1 && !vis[n - 1][j]) {
                dfs(n - 1, j, grid, vis, n, m);
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};