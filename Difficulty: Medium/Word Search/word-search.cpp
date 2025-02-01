//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool found=false;
  void search(vector<vector<char>>&mat,string &word,int wordind,int i,int j){
      if(wordind==word.size()){
          found=true;
          return;
      }
      int n=mat.size(),m=mat[0].size();
      if(i>=0 && j>=0 && i<n && j<m){
          
      
      if(mat[i][j]!=word[wordind]){
          return;
      }
      char back=mat[i][j];
      mat[i][j]='-';
      search(mat,word,wordind+1,i+1,j);
      search(mat,word,wordind+1,i-1,j);
      search(mat,word,wordind+1,i,j+1);
      search(mat,word,wordind+1,i,j-1);
      mat[i][j]=back;
      }
      
  }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
       for(int i=0;i<mat.size();i++){
           for(int j=0;j<mat[0].size();j++){
               if(mat[i][j]==word[0]){
                   search(mat,word,0,i,j);
               }
           }
       }
        
        return found;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends