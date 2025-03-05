//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int>res={INT_MIN,INT_MAX};
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=x && res[1]>arr[i]){
                res[1]=arr[i];
            }
            if(arr[i]<=x && res[0]<arr[i]){
                res[0]=arr[i];
            }
        }
        if(res[0]==INT_MIN){
            res[0]=-1;
        }
        if(res[1]==INT_MAX){
            res[1]=-1;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends