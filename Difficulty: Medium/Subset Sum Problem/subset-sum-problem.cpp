//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<bool>prev(sum+1, 0);
        prev[0]=1;
        for(int i=1; i<=n; i++){
            vector<bool>curr(sum+1, 0);
            curr[0]=1;
            for(int t=0; t<=sum; t++){
                bool take=0;
                if(t>=arr[i-1]) take=prev[t-arr[i-1]];
                curr[t]=take|prev[t];
            }
            prev=curr;
        }
        return prev[sum];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends