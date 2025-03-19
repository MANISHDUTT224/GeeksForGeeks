//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int mid,int n,int m){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=mid;
            if(ans>m){
                return 2;
            }
        }
        if(ans==m){
            return 1;
        }
        return 0;
    }
    int nthRoot(int n, int m) {
        // Code here.
        int i=1,j=m;
        while(i<=j){
            int mid=(i+j)/2;
            if(solve(mid,n,m)==1){
                return mid;
            }
            else if(solve(mid,n,m)==2){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends