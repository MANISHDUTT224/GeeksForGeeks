//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<char>>&grid,int i,int j,int& n,int& m){
        if( i<0 || j<0 || i>=n || j>=m||grid[i][j]=='W'){
            return;
        }
        grid[i][j]='W';
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j-1,n,m);
        dfs(grid,i-1,j+1,n,m);
        dfs(grid,i+1,j-1,n,m);
        dfs(grid,i+1,j+1,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
       
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    islands++;
                    dfs(grid,i,j,n,m);
                    
                }
            }
        }
        return islands;
    }
    
    
    // void solve(vector<vector<char>>&grid,int i,int j,int& n,int& m){
    //     if(i<0 ||j <0 || i>=n ||j >=m || grid[i][j] =='W')return;
    //     grid[i][j] = 'W';
    //     solve(grid,i+1,j,n,m);
    //     solve(grid,i-1,j,n,m);
    //     solve(grid,i,j+1,n,m);
    //     solve(grid,i,j-1,n,m);
    //     solve(grid,i+1,j+1,n,m);
    //     solve(grid,i+1,j-1,n,m);
    //     solve(grid,i-1,j-1,n,m);
    //     solve(grid,i-1,j+1,n,m);
    // }
    // int countIslands(vector<vector<char>>& grid) {
    //     int n = grid.size();
    //     int m =grid[0].size();
    //     int count = 0;
    //     for(int i = 0;i<n;i++){
    //         for(int j =0;j<m;j++){
    //             if(grid[i][j] == 'L'){
    //                 count++;
    //                 solve(grid,i,j,n,m);
    //             }
    //         }
    //     }
    //     return count;
        
    // }


    
    
    
    
    
    
    
    
    
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends