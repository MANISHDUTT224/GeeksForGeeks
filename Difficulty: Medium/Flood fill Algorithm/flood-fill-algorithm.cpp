//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void floodFillUtil(vector<vector<int>>&image,vector<vector<bool>>&visited,vector<vector<int>>directions,int sr,int sc,int n,int m,int prevColor,int newColor){
        image[sr][sc]=newColor;
        visited[sr][sc]=true;
        for(auto dir:directions){
            int row=sr+dir[0],col=sc+dir[1];
            
        if(row>=0 && col>=0 && row<n && col<m && image[row][col]==prevColor && !visited[row][col]){
            floodFillUtil(image,visited,directions,row,col,n,m,prevColor,newColor);
        }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n=image.size(),m=image[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
         vector<vector<int>> directions={{-1,0},{0,-1},{0,1},{1,0}};
        int prevColor=image[sr][sc];
        floodFillUtil(image,visited,directions,sr,sc,n,m,prevColor,newColor);
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends