//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
       int n=coins.size();
       vector<int>dp(sum+1,sum+1);
       dp[0]=0;
       for(int coin:coins){
           for(int j=coin;j<=sum;j++){
               dp[j]=min(dp[j],dp[j-coin]+1);
           }
       }
       if(dp[sum]==sum+1){
           return -1;
       }
       return dp[sum];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends