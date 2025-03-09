//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
   
   int cntPalin(string &s,int i,int j){
      int cnt=0;
      while(i>=0 && j< s.size() ){
          if(s[i]==s[j]){
              if((j-i+1)>=2) cnt++;
              i--;
              j++;
          }
          else break;
      }
      return cnt;
  }
  
  
    int countPS(string &s) {
        // code here
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            res +=cntPalin(s,i,i+1);
            res +=cntPalin(s,i,i);
        }
        return res;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends