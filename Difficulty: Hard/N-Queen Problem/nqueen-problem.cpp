//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>>res;
    void solve(int col,vector<vector<int>>&board,vector<int>&temp,vector<int>&leftrow,vector<int>&lowdiag,vector<int>&updiag){
        int n=board.size();
        if(col==n){
            res.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowdiag[col+row]==0 && updiag[col-row+n-1]==0){
                board[row][col]=1;
                leftrow[row]=1;
                lowdiag[col+row]=1;
                updiag[col-row+n-1]=1;
                temp.push_back(row+1);
                solve(col+1,board,temp,leftrow,lowdiag,updiag);
                temp.pop_back();
                 board[row][col]=0;
                leftrow[row]=0;
                lowdiag[col+row]=0;
                updiag[col-row+n-1]=0;
                
            }
        }
    }
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>board(n,vector<int>(n));
        vector<int>temp;
        vector<int>leftrow(n),lowdiag(2*n-1),updiag(2*n-1);
        solve(0,board,temp,leftrow,lowdiag,updiag);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends