//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void findcomb(string s,int l,int r,set<string>&ans){
      if(l==r){
         
          ans.insert(s);
          
          return;
      }
      for(int i=l;i<=r;i++){
          swap(s[i],s[l]);
          findcomb(s,l+1,r,ans);
          swap(s[i],s[l]);
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        int l=0,r=s.size()-1;
        set<string>ans;
        findcomb(s,l,r,ans);
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends