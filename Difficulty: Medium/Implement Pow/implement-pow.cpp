//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e1) {
        // code here
        double ans=1;
        int e=abs(e1);
        
       while(e){
           if(e%2==1){
               e--;
               ans*=b;
           }
           else{
               e/=2;
               b*=b;
           }
       }
       if(e1<0){
           return 1/ans;
       }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends