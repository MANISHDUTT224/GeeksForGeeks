//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isValid(vector<vector<int>>&grid,int r,int c,int digit){
        for(int i=0;i<9;i++){
            if(grid[i][c]==digit || grid[r][i]==digit||grid[(r/3)*3+(i/3)][(3*(c/3))+(i%3)]==digit){
                return false;
            }
            
        }
        return true;
    }
    bool solve(vector<vector<int>>&board){
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    bool found=false;
                    for(int num=1;num<=9;num++){
                       
                        if(isValid(board,i,j,num)){
                             board[i][j]=num;
                           if(solve(board)){
                               return true;
                           }
                           else{
                                board[i][j]=0;
                           }
                        }
                       
                    }
                    return false;
                    
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends