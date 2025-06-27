//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>>res;
        for(int i=1;i<=n;i++){
            vector<int>arr;
            int temp=1;
            arr.push_back(temp);
            for(int j=1;j<i;j++){
                temp*=(i-j);
                temp/=j;
                arr.push_back(temp);
            }
            res.push_back(arr);
        
        }
        return res[n-1];
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends