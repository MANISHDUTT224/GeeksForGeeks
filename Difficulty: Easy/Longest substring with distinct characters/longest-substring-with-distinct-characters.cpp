//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n=s.size();
       unordered_set<char>st;
       int maxlen=0;
       int S=0;

       for( int i=0;i<s.size();i++){
           while(st.find(s[i])!=st.end()){
               st.erase(s[S]);
               S++;
           }
           st.insert(s[i]);
           maxlen=max(maxlen,i-S+1);
          
       }
       return maxlen;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends