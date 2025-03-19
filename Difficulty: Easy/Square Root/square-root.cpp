//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int i=1,j=n;
        while(i<=j){
            int mid=(i+j)/2;
            long long val=mid*mid;
            if(val<=(long long)n){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return j;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends