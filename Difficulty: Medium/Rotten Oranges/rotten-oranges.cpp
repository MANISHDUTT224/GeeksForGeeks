//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int dx[4]={-1,0,1,0};
  int dy[4]={0,-1,0,1};
  bool isValid(int i,int j,int n,int m,vector<vector<int>>&mat){
      if(i>=0 && j>=0 && i<n && j<m && mat[i][j]==1){
          return true;
      }
      return false;
  }
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,pair<int,int>>>q;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,{j,0}});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            auto z=q.front();
            int ix=z.first;
            int jy=z.second.first;
            int cost=z.second.second;
            ans=max(ans,cost);
            q.pop();
            for(int k=0;k<4;k++){
                int row=ix+dx[k];
                int col=jy+dy[k];
                if(isValid(row,col,n,m,mat)){
                    q.push({row,{col,cost+1}});
                    mat[row][col]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends